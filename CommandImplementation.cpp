#include<iostream>
#include<string>

#include"Buffer.h"
#include"CommandImplementation.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;

CommandImplementation::CommandImplementation(Buffer * bufferObj) : bufferObj(bufferObj){}

/*implementation for append command*/
bool CommandImplementation::append(int start, int end, vector<string>& text){

	/*start = -2 for currentPtr*/
	if (start == -2){
		start = end = bufferObj->getCurrentPtr()+1;
		
	}

	/*start = -3 for last index*/
	if (start == -3){
		start = end = bufferObj->getBufferList().size()-1;
	}
	
	/*Condiion to check validity of append index*/
	if (start <= 0 || start > bufferObj->getBufferList().size()){
		return false;
	}

	auto it = bufferObj -> getBufferList().begin(); /*Declaring an interator with value begin it=0*/

	int i = 0; /*To keep count of new elements entered*/

	/*set i to append index*/
	for (i = 0; i < start; ++i){
		++it;
	}

	for (string & t : text) {
		bufferObj->getBufferList().insert(it, t);
		++i;
	}

	
	/*setting currentPtr to insert index*/
	bufferObj -> getCurrentPtr() = i;

	return true;
}

/*implementation for insert command*/
bool CommandImplementation::insert(int start, int end, vector<string> & text){
	
	/*start = -2 for currentPtr*/
	if (start == -2){
		start = end = bufferObj->getCurrentPtr()+1;
	}

	/*start = -3 for last index*/
	if (start == -3){
		start = end = bufferObj->getBufferList().size() - 1;
	}

	/*condition to check empty buffer*/
	if (bufferObj -> getBufferList().empty()){ return false; }

	/*Condiion to check validity of append index*/
	if (start <= 0 || start > bufferObj->getBufferList().size()){
		return false;
	}

	auto it = bufferObj -> getBufferList().begin(); /*Declaring an interator with value begin it=0*/

	int i = 0; /*To keep count of new elements entered*/

	/*set i to append index*/
	for (i = 0; i < start; ++i){
		++it;
	}

	for (string & t : text) {
		bufferObj -> getBufferList().insert(it, t);
		++i;
	}

	/*setting currentPtr to insert index*/
	bufferObj -> getCurrentPtr() = i;

	return true;
}


bool CommandImplementation::remove(int start, int end){
	
	/*start = -2 for currentPtr*/
	if (start == -2){
		start = bufferObj->getCurrentPtr() + 1;
	}

	/*start = -3 for last index*/
	if (start == -3){
		start = bufferObj->getBufferList().size() - 1;
	}

	/*end = -2 for currentPtr*/
	if (end == -2){
		end = bufferObj->getCurrentPtr() + 1;
	}

	/*end = -3 for last index*/
	if (end == -3){
		end = bufferObj->getBufferList().size() - 1;
	}

	/*Condiion to check validity of append index*/
	if (start <= 0 || start > bufferObj->getBufferList().size()){
		return false;
	}


	/*Condiion to check validity of append index*/
	if (end <= 0 || end > bufferObj->getBufferList().size()){
		return false;
	}

	--start;
	--end;

	int i;

	auto itStart = bufferObj->getBufferList().begin();
	for (i = 0; i < start; ++i){
		++itStart;
	}

	auto itEnd = bufferObj->getBufferList().begin();
	for (i = 0; i < end + 1; ++i){
		++itEnd;
	}

	/*Removing elements*/
	auto it1 = bufferObj->getBufferList().erase(itStart, itEnd);

	if (it1 == bufferObj->getBufferList().end()){
		bufferObj->getCurrentPtr() = bufferObj->getBufferList().size()-1;
	}
	else{
		bufferObj->getCurrentPtr() = end + 1 - (end - start + 1);
	}

	return true;
}


bool CommandImplementation::print(int start, int end){
	
	/*start = -2 for currentPtr*/
	if (start == -2){
		start = bufferObj->getCurrentPtr() + 1;
	}

	/*start = -3 for last index*/
	if (start == -3){
		start = bufferObj->getBufferList().size() - 1;
	}

	/*end = -2 for currentPtr*/
	if (end == -2){
		end = bufferObj->getCurrentPtr() + 1;
	}

	/*end = -3 for last index*/
	if (end == -3){
		end = bufferObj->getBufferList().size() - 1;
	}

	

	/*Condiion to check validity of append index*/
	if (start <= 0 || start > bufferObj->getBufferList().size()){
		return false;
	}

	
	/*Condiion to check validity of append index*/
	if (end <= 0 || end > bufferObj->getBufferList().size()){
		return false;
	}
	
	--start;
	--end;
	int i;

	auto itStart = bufferObj->getBufferList().begin();
	for (i = 0; i < start; ++i){
		++itStart;
	}

	auto itEnd = bufferObj->getBufferList().begin();
	for (i = 0; i < end+1; ++i){
		++itEnd;
	}

	/*printing elements*/
	for (auto it = itStart; it != itEnd; ++it){
		cout << *it << endl;
	}

	bufferObj->getCurrentPtr() = i-1;
	return true;
}


bool CommandImplementation::printWithLineNo(int start, int end){

	/*start = -2 for currentPtr*/
	if (start == -2){
		start = bufferObj->getCurrentPtr() + 1;
	}

	/*start = -3 for last index*/
	if (start == -3){
		start = bufferObj->getBufferList().size() - 1;
	}

	/*end = -2 for currentPtr*/
	if (end == -2){
		end = bufferObj->getCurrentPtr() + 1;
	}

	/*end = -3 for last index*/
	if (end == -3){
		end = bufferObj->getBufferList().size() - 1;
	}



	/*Condiion to check validity of append index*/
	if (start <= 0 || start > bufferObj->getBufferList().size()){
		return false;
	}


	/*Condiion to check validity of append index*/
	if (end <= 0 || end > bufferObj->getBufferList().size()){
		return false;
	}

	--start;
	--end;
	int i;

	auto itStart = bufferObj->getBufferList().begin();
	for (i = 0; i < start; ++i){
		++itStart;
	}

	auto itEnd = bufferObj->getBufferList().begin();
	for (i = 0; i < end + 1; ++i){
		++itEnd;
	}

	int count = start + 1;

	/*printing elements*/
	for (auto it = itStart; it != itEnd; ++it){
		cout <<count<<" " <<*it << endl;
		++count;
	}

	bufferObj->getCurrentPtr() = i - 1;
	return true;
}


bool CommandImplementation::change(int start, int end){

	/*start = -2 for currentPtr*/
	if (start == -2){
		start = bufferObj->getCurrentPtr() + 1;
	}

	/*start = -3 for last index*/
	if (start == -3){
		start = bufferObj->getBufferList().size() - 1;
	}

	/*end = -2 for currentPtr*/
	if (end == -2){
		end = bufferObj->getCurrentPtr() + 1;
	}

	/*end = -3 for last index*/
	if (end == -3){
		end = bufferObj->getBufferList().size() - 1;
	}



	/*Condiion to check validity of append index*/
	if (start <= 0 || start > bufferObj->getBufferList().size()){
		return false;
	}


	/*Condiion to check validity of append index*/
	if (end <= 0 || end > bufferObj->getBufferList().size()){
		return false;
	}

	--start;
	--end;
	
	string original;
	string newStr;

	cout << "Enter string to be replaced"<<endl;
	cin >> original;

	cout << "Enter new string";
	cin >> newStr;

	int i;

	auto itStart = bufferObj->getBufferList().begin();
	for (i = 0; i < start; ++i){
		++itStart;
	}

	auto itEnd = bufferObj->getBufferList().begin();
	for (i = 0; i < end + 1; ++i){
		++itEnd;
	}

	/*printing elements*/
	for (auto it = itStart; it != itEnd; ++it){
			int j = it->find(original);
			while (j != string::npos) {
				it->replace(j, original.length(), newStr);
				j = it->find(original, j + original.length());
			}
		}	

	bufferObj->getCurrentPtr() = i - 1;

	return true;
}



bool CommandImplementation::moveLineAddressUp(int start){

	int temp = bufferObj->getCurrentPtr();
	temp -= start;

	/*Condiion to check validity of getCurrent*/
	if (temp < 1){
		temp = 0;
	}

	bufferObj->getCurrentPtr() = temp;

	return true;
}


bool CommandImplementation::moveLineAddressDown(int start){
	int temp = bufferObj->getCurrentPtr();
	temp += start;

	/*Condiion to check validity of getCurrent*/
	if (temp > bufferObj->getBufferList().size()){
		temp = bufferObj->getBufferList().size()-1;
	}

	bufferObj->getCurrentPtr() = temp;

	return true;
}


bool CommandImplementation::writeBufferToFile(){
	bufferObj->flushBuffer();
	return true;
}

