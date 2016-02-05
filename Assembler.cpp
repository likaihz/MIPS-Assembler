#include "Assembler.h"
//#include "format.h"
//#include "label.h"
using namespace std;

void Assembler::Format()
{
	/*
	 * functions:
	 * 	erase empty lines;
	 * 	erase white blanks at the beginning and end of each line;
	 *	put the label in a new line;
	 */
	auto it = lines.begin();
	while(it != lines.end() )
	{
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
