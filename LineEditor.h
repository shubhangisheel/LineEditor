#ifndef LineEditor_H
#define LineEditor_H

#include<string>
#include "Buffer.h";

/*This class is the view in model-view-controller framework*/

class LineEditor{
private: Buffer buf; /*Object of buffer to access list containing file*/
		 string filename; /*filename to be read or edited*/

public: LineEditor(const string&); /*ctor receiving filename*/
		void run(); /*function from where program logic executes*/
};

#endif