#ifndef _LABEL_H_
#define _LABEL_H_

#define LABEL_AT_MOST 2048				//the number of labels in a file is 2048 at most
#include <string>
#include <iostream>

public class Label{
	string label;
	int location;
}

int Get_label(Label label[], ifstream fin);

#endif
