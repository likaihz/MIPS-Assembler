#include <fstream>
#include <iostream>
#include <string>
#include "label.h"

using namespace std;

int Get_label(Label lebel[], ifstream fin)
{
	string buf = "" , tmp = "";
	
	int cnt_line = 0, cnt_lbl = 0;
	while(!fin.eof())
	{
		getline(fin, buf);
		string::iterator it;
		for(it = buf.begin(); it != buf.end(); )
		{
			if( *it == ' ' || *it = '\t')
				buf.erase(it);
			else
				it++;
		}												//delete all the blanks in each line

		if(!buf.empty())
			cnt_line ++;
		
		if(0 <= buf.find(":") && buf.find(":") < buf.length())
		{
			tmp = buf.substr(0, buf.find(":"));
			label[cnt_lbl].label = tmp;
			if(buf.find(":") == buf.length()-1)
			{
				cnt_line --;
				label[cnt_lbl].location = cnt_line;
			}
			else
				label[cnt_lbl].location = cnt_line -1;

			if((++cnt_lbl) >= LABEL_AT_MOST)
			{
				cout << "Too many labels!" << endl;
				exit(0);
			}
		}


	}

	return cnt_lbl;
}
