/* 汇编器主程序*/

#include <fstream>
#include <iostream>
#include <string>
#include "Assembler.h"
#include "format.h"
#include "label.h"

using namespace std;

int Assembler(string fname)
{
	Label label[LABEL_AT_MOST];
	int i, cnt_lbl, cnt_line;

	cnt_lbl = Get_Label(label, fname);
	ifstream fin(fname);
	ofstream fout;
	fout.open(/********??*********/);
	fout.close();			//清空目标文件的内容

	if(!fin)
	{
		cout << "The asm file does not exist!" << endl;
		exit(0);
	}

	while(!fin.eof())
	{
		string buf = "", ir, res ;
		getline(fin, buf);
		string::iterator it;
		for(it = buf.begin(); it != buf.end(); )		//
		{
			if(*it == ' ' || *it == '\t')
				buf.erase(it);
			else
				it++;
		}
		if(buf.
		if(buf.empty())
			continue;

	}

}

int main()
{
	return 0;
}

