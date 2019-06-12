#include "../includes/Scanner.h"
#include "../includes/Token.h"
#include "../includes/String.h"
#include <math.h>
#include <fstream>

#include <iostream>

int main(int argc, char **argv) {
	cout << "woops test" << endl;


//	Scanner scanner("testo3.txt");
//	ofstream outFile;
//	outFile.open("sample.txt");
//
//	Token* token = scanner.getToken();
//	while (!scanner.hasFileEnded()) {
//
//		if (token->geTokenType() == ERROR) {
//			token->print();
//			cerr << token->tokenToString() << endl;
//		} else {
//			token->print();
//			outFile << token->tokenToString() << endl;
//		}
//
//		token = scanner.getToken();
//	}
//	outFile.close();


// Versuch aus Terminal zu starten
	 char *inFile = argv[1];
	const char *outFilename = argv[2];
	Scanner scanner (inFile);
	Token* token = scanner.getToken();
	cout<<token->tokenTypeToString();
	cout<<"meep"<<endl;

}

