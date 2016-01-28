#include <fstream>
#include <iostream>
#include <string>
#include "format.h"
using namespace std;
string Erase_Comment(string line)
{
	//cout << line << endl;
	//cout << string::npos <<endl;
	int pos, pos1, pos2;
	pos1 = line.find("//", 0 );
	pos2 = line.find("#", 0);

	if(pos1  == string::npos && pos2  == string::npos)
		return line;

	pos = (pos1 < pos2 && pos1 >=0)?pos1:pos2;
	//cout << pos1<< " " <<pos2 << endl;
	//cout << pos <<endl;

	string::iterator it;
	it = line.begin();
	for(int i=0; i<pos; i++)
		it ++;
	
	//it += (pos - 1);
	line.erase(it, line.end());

	return line;
	
}
/*
int main()
{
	string t1("xxw #sss\n");

	t1 = Erase_Comment(t1);

	cout << t1 << endl;
}*/
