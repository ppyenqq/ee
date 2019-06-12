#pragma once

#include "TokenType.h"
#include "../../Symboltable/includes/Info.h"
#include "String.h"

class Token
{
private:
	TokenType mType;
	int mLine, mColumn;
	int mInformation;
	char mErrorSign;
	Info* mKey;

public:
	Token(TokenType type, int line, int column);
	Token(TokenType type, int line, int column, int information);
	Token(TokenType type, int line, int column, Info* key);
	Token(int line, int column, char errorSign);
	~Token();
const char* tokenTypeToString();
	void print();
	const char* tokenToString();

	TokenType geTokenType() {
		return mType;
	}
	int getLine() {
		return mLine;
	}
	int getColumn() {
		return mColumn;
	}
	Info* getKey() {
		return mKey;
	}
	int getInformation() {
		return mInformation;
	}
	char getErrorSign() {
		return mErrorSign;
	}
};
