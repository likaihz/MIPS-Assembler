/* 汇编器主程序*/

#include <fstream>
#include <iostream>
#include <string>
#include "assembler.h"
#include "comment.h"
#include "label.h"

using namespace std;

int Assembler(string ifname)
{
	Label label[LABEL_AT_MOST];
	int i, cnt_lbl, cnt_line;

	cnt_lbl = Get_Label(label, fname);
	ifstream fin(fname);

}

int main()
{
	return 0;
}

