#include<iostream>
#include<string>
#include"CommandParser.h"
using std::string;



CommandParser::Command CommandParser::getCommand(string& command){

	Command commandObj;

	if (command.empty()) {
		commandObj.valid = false;
		return commandObj;
	}

	// Trim the command
	std::string newCommand{ trim(command) };


	// determine if only valid symbols are present else set invlaid

	std::size_t found_invalid = newCommand.find_first_not_of("airpncudwq.$,0123456789=");
	if (found_invalid != std::string::npos) {
		std::cout << "Invalid Command" << std::endl;
		commandObj.valid = false;
		return commandObj;
	}


	// Look for first command characters and 
	// see if any others are present scanning from behind else invalid

	std::size_t found_symbol = newCommand.find_first_of("airpncudwq=");
	std::size_t found_other = newCommand.find_last_of("airpncudwq=");
	if (found_symbol != found_other){
		std::cout << "Invalid Command" << std::endl;
		commandObj.valid = false;
		return commandObj;
	}
	else if (found_symbol != std::string::npos) {
		commandObj.cmd = command[found_symbol];
	}



	//look for occurrence of comma if none
	//iif more than one invalid
	// if only a number store it to the address field

	std::size_t found_comma = newCommand.find_first_of(",");
	std::size_t found_comma_other = newCommand.find_last_of(",");
	std::size_t lone_number = newCommand.find_first_of("0123456789");
	if (found_comma != found_comma_other){
		std::cout << "Invalid Command" << std::endl;
		commandObj.valid = false;
		return commandObj;
	}
	else if (found_comma != std::string::npos) {
		commandObj.begin = newCommand.substr(0, found_comma);
		commandObj.end = newCommand.substr(found_comma + 1, newCommand.length() - 2 - found_comma);
	}
	else if (found_symbol != std::string::npos) {
		commandObj.begin = newCommand.substr(0, found_symbol);
		commandObj.end = commandObj.begin;
	}
	else if (lone_number != std::string::npos){
		commandObj.begin = newCommand.front();
		commandObj.end = commandObj.begin;
	}



	// store default address to default current if empty


	if (commandObj.begin.empty() && commandObj.end.empty()) {
		//commandObj.begin = ".";
		commandObj.begin = "-2";
		//commandObj.end = ".";
		commandObj.end = "-2";
	}
	else if (commandObj.begin.empty()) {
		if (commandObj.end == "$"){
			// have to change end to -2 as well
			commandObj.end = "-3";
			//commandObj.begin = "$";
			commandObj.begin = "-3";
		}
		else{
			//commandObj.begin = ".";
			commandObj.begin = "-2";
		}
	}
	else if (commandObj.end.empty()) {
		if (commandObj.begin == "$"){
			// have to change begin to -3 as well
			commandObj.begin = "-3";
			//commandObj.end = "$";
			commandObj.end = "-3";
		}
		else{
			//commandObj.end = ".";
			commandObj.end = "-2";
		}
	}


	// Set address validity to true
	commandObj.valid = true;

	return commandObj;
}


std::string CommandParser::trim(std::string& str)
{
	size_t first = str.find_first_not_of(' ');
	size_t last = str.find_last_not_of(' ');
	return str.substr(first, (last - first + 1));
}