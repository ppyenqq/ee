#include "../includes/Scanner.h"
#include "../includes/Token.h"
#include "../includes/String.h"//wenn man String.h benutzt bekommt man undefined reference,bitte beheben wenn Zeit zu verfügung steh
#include "../../Symboltable/includes/SymtabEntry.h"
#define BLANK ' '
#include <iostream>

Scanner::Scanner(char* fileName) {
	std::cout << "[SCANNER CONSTRUCTOR] : " << this << std::endl;

	this->automat = new Automat();
	this->buffer = new Buffer(fileName);
	this->symboltable = new Symboltable();
	fileEnded=false;

}

Scanner::~Scanner() {
	delete automat;
	delete buffer;
	delete symboltable;
}

Token* Scanner::getToken() {

	int line;//der hier ist fortlaufend, also "currentLine", während tokenLine die Start-Line/Column eines Token ist
	int column;
	int tokenLine;
	int tokenColumn;
	bool legal;

	String lexem("");
	TokenType lastValidTokenType;

	do {


		char c = buffer->getChar();
		line = buffer->getLine();
		column = buffer->getColumn();
		// check EOF
		if (c == '\0') {

			if (lexem.length > 0){


				return new Token(lastValidTokenType, tokenLine, tokenColumn);
			}
			fileEnded=true;
			return nullptr;

		}

		legal = automat->step(c);

		//std::cout << "[SCANNER] " << "c: " << c << std::endl;
		//std::cout << "[SCANNER] " << "legal: " << legal << std::endl;
		//std::cout << "[SCANNER] " << "lexem length: " << lexem.length << std::endl;

		if (legal) {
			lexem += c;
			lastValidTokenType = automat->getTokenType();
			if(lexem.length==1){
				tokenLine=line;
				tokenColumn=column;
			}
		} else if (lexem.length > 0) {
			if (automat->getTokenType() == COMMENT_START) {

				// run to end of comment
		// !!!!!!!!!!!!!!!!!!!!!! NACHFRAGEN was passiert , wenn mit Comment_End angefangen wird oderdas Comment nicht endet-> ist das nciht aufgabe von PARSER??????????
				char lastChar = c;
				while (!(c == ':' && lastChar == '*') && c != '\0') {
					lastChar = c;
					c = buffer->getChar();
				}
				automat->reset();
				lexem.length=0;
				legal = true;

			} else {

				// build token
				Token* token;
				if (lastValidTokenType == IDENTIFIER) {
					SymtabEntry* keyOne = symboltable->insert(lexem.get(),
							lastValidTokenType);//versuch lastValidTokenType mit automat->getTokenType zu wechseln, glaube mach keinen Unterschied
					Info* mainKey = symboltable->lookup(keyOne);
					token = new Token(mainKey->getTokenType(), tokenLine, tokenColumn, mainKey);
				} else if (lastValidTokenType == INTEGER) {
					int value = lexem.stringToInt();
					token = new Token(lastValidTokenType, tokenLine, tokenColumn, value);
				} else {
					token = new Token(lastValidTokenType, tokenLine, tokenColumn);
				}

				// reset
				automat->reset();
				buffer->ungetChar();
				lexem -= lexem.length - 1;

				return token;
			}
		} else if(c==' '||c=='\n'||c=='\r'||c=='\t'||c=='\a'||c=='\b'||c=='\v'||c=='\f'){
			//cout << "Leerzeichnen oder  Steuerzeichen( wie newline oder Tab ) "<<endl;
			if(c=='\t'){
				column+=3;
			}
			automat->reset();
			legal=true;
		}else{
			automat->reset();
			return new Token(line, column, c);
		}

	} while (legal);
//UNtere Teil ist unnötig oder ?
//	Token* token = new Token(lastValidTokenType, line, column);
//	automat->reset();
//	lexem -= lexem.length - 1;

	return nullptr;
}

Symboltable* Scanner::getSymboltable() {

	return symboltable;
}

