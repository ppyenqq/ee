#include "../includes/Scanner.h"
#include "../includes/Token.h"
#include "../includes/Taken.h"
#include <iostream>

int main(int argc, char **argv) {
	cout<<"woops test"<<endl;
//	Token* token = new Token(INTEGER,2,5,1);
//	token->print();
//	TokenType* finalStates = new TokenType[25];
//	TokenType lastValidTokenType = INTEGER;
//	cout<<lastValidTokenType<<endl;

//	Scanner scanner("../../testo.txt");
//	scanner.getrab();

//	Taken* taken= new Taken(1,1);
//	taken->print();

//	Token* token ;
//	token= new Token(INTEGER, 1, 1, 5);
//	token->print();
	char  *testFile ="input";

	Scanner scanner(testFile);

	for (int i = 0; i < 7; i++) {
		Token* token = scanner.getToken();
		if (token) {
			token->print();
		} else {
			std::cout << "EOF" << std::endl;
		}
	}


}
