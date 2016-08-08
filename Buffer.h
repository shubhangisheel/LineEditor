#ifndef BUFFER_H
#define BUFFER_H

#include<string>
#include<list>
#include<fstream>

using std::string;
using std::list;

/* This class owns and manages the buffer which is a list with file content*/
class Buffer{

private: list<string> buf; /*Creating list of strings to store file*/
		 int currentPtr; /*Pointer to keep track of file cursor or list current element*/
		 string filename; /*file name*/

public:
	Buffer(const string&); /*ctor for buffer, accepts filename*/
	void flushBuffer();

	list<string>& getBufferList();
	int& getCurrentPtr();

private:
	void copyFileToList(); /* function to copy file into linked list*/
};
#endif

