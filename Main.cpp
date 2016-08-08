#include<iostream>
#include "Buffer.h"
#include <list>
#include <string>
#include <vector>
#include "CommandImplementation.h"
#include "LineEditor.h"

using namespace std;
int main(int argv, char *argc[]){

	if (argv < 2) {
		cout << "File name not specified" << endl;
		return 0;
	}

	string filename(argc[1]);
	LineEditor ed(filename);
	ed.run();

	system("pause");
	return 0;

}