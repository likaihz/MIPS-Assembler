/*功能：对源文件进行预处理，去掉注释和空行
 *
 *
 *
 *
 */

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

void PrePro(string fname)
{
//	int i;
	ifstream fin(fname);
	ofstream fout("code");
	string buf = "";
	string des = "";

	bool empty = true;

	while(!fin.eof())
	{
		getline(fin, buf);
		string::iterator it;
		for(it = buf.begin(); it != buf.end();)
		{

		}
	}

}
 
