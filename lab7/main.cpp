#include <sstream>
#include <string>
#include <iostream>
using namespace::std;
#include <fstream>

void writeData(string fileName);
void readData(string fileName);


int main(int argc, char*argv[]) {

		std::stringstream fileName;
		fileName << argv[1] << "_" << argv[2] << ".txt";
			    	    	    
		writeData(fileName.str());	
		readData(fileName.str());
}


void writeData(string fileName) {
	    std::ofstream outputFile;
		outputFile.open(fileName.c_str());
		string passString;
		cout << "Press enter to exit" << endl;
	    getline(cin,passString);
	    while(passString != "") {
				outputFile << passString;
				getline(cin,passString);
		        outputFile << endl;
		}
		outputFile.close();
}


void readData(string fileName) {
	    cout << "the file data is: " << endl;
	    std::ifstream inputFile;	
		inputFile.open(fileName.c_str());
		std:: string nextVal;
		while(getline(inputFile,nextVal))
				cout << nextVal << endl;
		inputFile.close();
}

