#include<iostream>
#include<string>
#include<list>
#include"LineEditor.h"
#include"Buffer.h"
#include "CommandParser.h"
#include"CommandImplementation.h"
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::stoi;

/*ctor receiving filename*/
LineEditor::LineEditor(const string& filename) : filename(filename), buf(Buffer(filename)){}

/*function from where program logic executes*/
void LineEditor::run(){

	CommandParser cmdParser;
	CommandParser::Command command;
	CommandImplementation cmdImpl(&buf);
	cout << "Entering command mode" << endl;
	string mode = "command";
	string input = "";
	string text = "";
	vector<string> insertText;

	cout << "Entering into Command Mode" << endl;

	while (input != "q"){

		if (mode == "command"){
			
			cout << ":";

			cin >> input;
			command = cmdParser.getCommand(input);

			if (command.cmd == 'a' || command.cmd == 'i'){
				mode = "input";
				
			}

			switch (command.cmd)
			{
			case 'r':
				if (cmdImpl.remove(stoi(command.begin, nullptr), stoi(command.end, nullptr))){
					cout << "Successfully removed !" << endl;
				}
				else{
					cout << "ERROR: Unsuccessful operation" << endl;
				}
				break;


			case 'p':
				if (cmdImpl.print(stoi(command.begin, nullptr), stoi(command.end, nullptr))){
					cout << "Successfully printed !" << endl;
				}
				else{
					cout << "ERROR: Unsuccessful operation" << endl;
				}
				break;

			case 'n':
				if (cmdImpl.printWithLineNo(stoi(command.begin, nullptr), stoi(command.end, nullptr))){
					cout << "Successfully printed !" << endl;
				}
				else{
					cout << "ERROR: Unsuccessful operation" << endl;
				}
				break;

			case 'c':
				if (cmdImpl.change(stoi(command.begin, nullptr), stoi(command.end, nullptr))){
					cout << "Successfully changed!" << endl;
				}
				else{
					cout << "ERROR: Unsuccessful operation" << endl;
				}
				break;

			case 'u':
				if (cmdImpl.moveLineAddressUp(stoi(command.begin, nullptr))){
					cout << "Successfully moved current line up !" << endl;
				}
				else{
					cout << "ERROR: Unsuccessful operation" << endl;
				}
				break;

			case 'd':
				if (cmdImpl.moveLineAddressDown(stoi(command.begin, nullptr))){
					cout << "Successfully moved current line done !" << endl;
				}
				else{
					cout << "ERROR: Unsuccessful operation" << endl;
				}
				break;

			case'w':
				if (cmdImpl.writeBufferToFile()){
					cout << "Successfully wrote buffer to file !" << endl;
				}
				else{
					cout << "ERROR: Unsuccessful operation" << endl;
				}
				break;

			default:
				
				break;
			}
		}


		else{
			cout << "Entering input mode" << endl;

			while (getline(cin, text)){

				if (text != "."){
					insertText.push_back(text);
				}
				else{
					mode = "command";
					cout << "Entering into Command Mode" << endl;
					break;
				}
			}

			if (command.cmd == 'a'){
				if (cmdImpl.append(stoi(command.begin, nullptr), stoi(command.end, nullptr), insertText))
				{
					cout << " Successfully appended !" << endl;
				}
				else{
					cout << "ERROR: Unsuccessful operation" << endl;
				}
			}
			else if (command.cmd == 'i'){
				if (cmdImpl.insert(stoi(command.begin, nullptr), stoi(command.end, nullptr), insertText)){
					cout << "Successfully inserted !" << endl;
				}
				else{
					cout << "ERROR: Unsuccessful operation" << endl;
				}
			}
			else{
				cout << "Invalid command" << endl;
			}

			
		}
	}
	buf.flushBuffer();
}