#include "../includes/Token.h"

#include <iostream>

Token::Token(TokenType type, int line, int column) {
	mType = type;
	mLine = line;
	mColumn = column;
}

Token::Token(TokenType type, int line, int column, int information) {
	mType = type;
	mLine = line;
	mColumn = column;
	mInformation = information;
}
Token::Token(TokenType type, int line, int column, SymtabEntry* key) {
	mType = type;
	mLine = line;
	mColumn = column;
	mKey = key;
}
Token::Token(int line, int column, char errorSign) {
	mType = ERROR;
	mLine = line;
	mColumn = column;
	mErrorSign = errorSign;
}

void Token::print() {
	std::cout << "Token " << tokenTypeToString() << " Line: " << mLine << " Column: " << mColumn;
	switch (mType)
	{
		break;
	case INTEGER:
		std::cout << " Value: " << mInformation;
		break;
	case IDENTIFIER:
		std::cout << " Key: " << mKey;
		break;
	case ERROR:
		std::cout << " ErrorSign: " << mErrorSign;
		break;
	default:
		break;
	}
	std::cout << std::endl;
}
const char* Token::tokenTypeToString(){
	switch(mType){
	case start: return "start";
	case SIGN_PLUS: return "SIGN_PLUS";
	case SIGN_MINUS: return "SIGN_MINUS";
	case SIGN_COLON: return "SIGN_COLON";
	case SIGN_STAR: return "SIGN_STAR";
	case SIGN_LESS: return "SIGN_LESS";
	case SIGN_GREATER: return "SIGN_GREATER";
	case SIGN_EQUALS: return "SIGN_EQUALS";
	case SIGN_ASSIGN: return "SIGN_ASSIGN";
	case SIGN_EQUALS_COLON_EQUALS: return "SIGN_EQUALS_COLON_EQUALS";
	case SIGN_EXCLAMATION: return "SIGN_EXCLAMATION";
	case SIGN_AND: return "SIGN_AND";
	case SIGN_SEMICOLON: return "SIGN_SEMICOLON";
	case SIGN_BRACKETOPEN: return "SIGN_BRACKETOPEN";
	case SIGN_BRACKETCLOSE: return "SIGN_BRACKETCLOSE";
	case SIGN_BRACEOPEN: return "SIGN_BRACEOPEN";
	case SIGN_BRACECLOSE: return "SIGN_BRACECLOSE";
	case SIGN_SQUAREBRACKETOPEN: return "SIGN_SQUAREBRACKETOPEN";
	case SIGN_SQUAREBRACKETCLOSE: return "SIGN_SQUAREBRACKETCLOSE";
	case SIGN_ERROR: return "SIGN_ERROR";
	case SIGN_COMPARE: return "SIGN_COMPARE";
	case COMMENT_START: return "COMMENT_START";
	case COMMENT_END: return "COMMENT_END";
	case ERROR: return "ERROR";
	case INTEGER: return "INTEGER";
	case IDENTIFIER: return "IDENTIFIER";
	case KEYWORD_WRITE: return "KEYWORD_WRITE";
	case KEYWORD_READ: return "KEYWORD_READ";
	case KEYWORD_IF: return "KEYWORD_IF";
	case KEYWORD_ELSE: return "KEYWORD_ELSE";
	case KEYWORD_WHILE: return "KEYWORD_WHILE";
	case KEYWORD_INT: return "KEYWORD_INT";
	default: return"Unknown Type in Method TokenTypeToString";
	}

}
