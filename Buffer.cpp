#include<iostream>
#include<string>
#include<list>
#include<fstream>
#include"Buffer.h"

using std::string;
using std::list;
using std::ifstream;
using std::ofstream;
using std::cout;
using std::endl;

/*ctor for buffer, accepts filename*/
Buffer::Buffer(const string& filename) :filename(filename), buf(list<string>()), currentPtr(0){
	copyFileToList();
}

/* function to copy file into linked list*/
void Buffer::copyFileToList(){

	ifstream is(filename); /*Creating file object*/
	string listElement;

	/*checking whether file is valid*/
	if (is.is_open()){
		/*inserting line from file into the list*/
		while (getline(is, listElement)) {
			buf.push_back(listElement);
		}
		currentPtr = buf.size()-1;
		/*printing statements to console*/
		cout << "\"" + filename + "\"" + " " << buf.size() << " lines" << endl;

		is.close();
	}
	else{
		/*creating a new file of filename in case file doesn't exist*/
		ofstream os(filename);
		cout << "\"" << "?" << "\"" << "[New File]";
		os.close();
	}
	return;
}

/*writing list to file*/
void Buffer::flushBuffer(){
	ofstream flushBuf(filename);

	for (auto & element : buf){
		flushBuf << element << endl;
	}

	cout << "\"" + filename + "\"" + " " << buf.size() << " lines written" << endl;

}

list<string>& Buffer::getBufferList(){
	return buf;
}

int& Buffer::getCurrentPtr(){
	return currentPtr;
}


