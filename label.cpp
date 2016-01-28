#include <fstream>
#include <iostream>
#include <string>
#include "format.h"
#include "label.h"

using namespace std;

int Get_label(Label label[], string fname)
{
	string buf = "" , tmp = "";
	
	int cnt_line = 0, cnt_lbl = 0;
	ifstream fin(fname);
	if(fin == NULL)
		return -1;									//exception!!!
	while(!fin.eof())
	{
		getline(fin, buf);
		buf = Erase_Comment(buf);
		string::iterator it;
		for(it = buf.begin(); it != buf.end(); )
		{
			if( *it == ' ' || *it == '\t')
				buf.erase(it);
			else
				it++;
		}												//delete all the blanks in each line

		if(!buf.empty())
			cnt_line ++;
		else
			continue;
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


int main()
{
	//ifstream fin("tt");
	string name("tt");
	Label label[LABEL_AT_MOST];
	int num = Get_label(label, name);

	for(int i=0; i < num; i++)
	{
		cout << label[i].label <<'\t' <<label[i].location<< endl;
			
	}
	return 0;
}

