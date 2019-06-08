#pragma once

#include "TokenType.h"
#include "../../Symboltable/includes/SymtabEntry.h"
#include "../../Symboltable/includes/Symboltable.h"
class Token
{
private:
	TokenType mType;
	int mLine, mColumn;
	int mInformation;
	char mErrorSign;
	SymtabEntry* mKey;
	const char* tokenTypeToString();
public:
	Token(TokenType type, int line, int column);
	Token(TokenType type, int line, int column, int information);
	Token(TokenType type, int line, int column, SymtabEntry* key);
	Token(int line, int column, char errorSign);
	~Token();

	void print();

	TokenType geTokenType() {
		return mType;
	}
	int getLine() {
		return mLine;
	}
	int getColumn() {
		return mColumn;
	}
	int getKey() {
		return mInformation;
	}
	int getInformation() {
		return mInformation;
	}
	char getErrorSign() {
		return mErrorSign;
	}
};
