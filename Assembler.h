#ifndef _ASSEMBLER_H_
#define _ASSEMBLER_H_

#include <fstream>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Assembler{
private:
	
	vector<string> lines;				//contents of the file to be assembled 
	string ofname;						//the name of the output file
	string ifname;						//the name of the input file
	map<string, int> label;

	void EraseComment();
	void ScanLabel();
	void Format();
	
public:

	int BaseAddr;
	int DataAddr;
	//constructor!
	Assembler(string & infile, string & outfile) : content(""), ifname(infile), ofname(outfile) {
		ifstream fin(ifname);
		//potential exceptions!
		
		string buf;
		while(!fin.eof()) {
			getline(fin, buf);
		//	content += buf + "\n";
			lines.push_back(buf);
		}
	}

	Assembler(string & name) {
		this -> Assembler(name, name);
	}


	//methods!!
	
	void PreProcess();
	

}

//int Assembler(string fname);
#endif
