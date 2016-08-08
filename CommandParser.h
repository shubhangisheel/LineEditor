#ifndef CommandParser_H
#define CommandParser_H
#include <string>
using std::string;



class CommandParser{



public: struct Command{
	string begin;
	string end;
	char cmd;
	bool valid;

	Command() : begin("."), end("."), cmd('p'), valid(false){}
};

		CommandParser() = default;
		~CommandParser() = default;
		Command getCommand(string&);
		std::string CommandParser::trim(string&);

};

#endif