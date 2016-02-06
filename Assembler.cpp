#include "Assembler.h"
//#include "format.h"
//#include "label.h"
using namespace std;

void Assembler::EraseComment()
{
	for(auto it = lines.begin(); it != lines.end(); it++ ) {
		int pos1 = it -> find("//");
		int pos2 = it -> find('#');
		int pos;
		if(pos1 == string::npos && pos2 == string::npos) continue;
		if(pos1 == string::npos || pos2 == string::npos) 
			pos = (pos1 == string::npos)?pos2:pos1;
		else
			pos = (pos1 < pos2 )?pos1:pos2;

		it -> erase(pos, it->length()-pos+1);
	}
}

void Assembler::Format()
{
	/*
	 * functions:
	 * 	erase empty lines;
	 * 	erase white blanks at the beginning and end of each line;
	 *	put the label in a new line;
	 */
	for(auto it = lines.begin(); it != lines.end(); it++ ) {
		int pos = find(':');
		if(pos == string::npos) continue;
		string buf = it -> substr(pos+1, it -> length()-pos);
		if(buf.empty()) continue;
		it->erase(pos+1, it -> length()-pos);
		lines.insert(++it, buf);
	}

	while(it != lines.end() ) {
		for(auto str_it = it -> begin(); str_it != it -> end(); ) {
			if(*str_it == ' ' || *str_it == '\t')
				it -> erase(str_it);
			else break;
		}
		auto str_rit = it -> rbegin();
		for( ; *str_rit == ' ' || *str_rit == '\t' ; str_rit ++ ) ;
		string::iterator str_it(str_rit.base() );
		it -> erase(str_it, it -> end() );

		if(it -> empty()) lines.erase(it);
		else it++;
	}
}

void Assembler::PreProcess()
{
	EraseComment();
	Format();
	ScanLabel();
}
