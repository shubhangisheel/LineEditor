#ifndef CommandImplementation_H
#define CommandImplementation_H
#include<string>
#include<vector>

#include"Buffer.h"
#include"CommandParser.h"

using std::string;
using std::vector;

/*This class defines functions that operate on the list*/
class CommandImplementation{

private: Buffer* bufferObj;

public: CommandImplementation(Buffer*); /*ctor receiving buffer object and command object */
		bool append(int, int, vector<string>&); /*command 'a'*/
		bool insert(int, int, vector<string>&); /*command 'i'*/
		bool remove(int, int); /*command 'r'*/
		bool print(int, int); /*command 'p'*/
		bool printWithLineNo(int, int); /*command 'n'*/
		bool change(int, int); /*command 'c'*/
		bool moveLineAddressUp(int); /*command 'u'*/
		bool moveLineAddressDown(int); /*command 'd'*/
		bool writeBufferToFile(); /*command 'w'*/
	};

#endif