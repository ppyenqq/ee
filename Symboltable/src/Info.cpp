/*
 * Info.cpp
 *
 *  Created on: 06.12.2018
 *      Author: jack
 */
#include "../includes/Info.h"

Info::Info() {
	name = nullptr;
	mTokenType = ERROR;
}

Info::~Info() {

}

/**
 * Setzt den TokenType
 */
void Info::setTokenType(TokenType tokenType){
	mTokenType = tokenType;
}

/**
 * Gibt den TokenTyp zurueck
 */
TokenType Info::getTokenType(){
	return mTokenType;
}
/**
 * Gibt einen Pointer auf den Namen zurueck.
 * (Pointer ist der Zeiger, der auf das Lexem in der StringTab zeigt.)
 */
char* Info::getNamePtr(){
	return name;
}

/**
 * Setzt den Pointer fuer den Namen.
 */
void Info::setNamePtr(char* namePtr){
	name = namePtr;
}

/**
 * Vergleicht zwei Lexeme.
 * Falls gleich -> true
 * falls nicht gleich -> false
 */
bool Info::compareLex(char* lexem){
	bool eq = false;
	while (*lexem != 0 && *name!= 0) {
		if(*name == *lexem){
			name++;
			lexem++;
			eq =true;
		}
		else{
			eq = false;
			break;
		}
	}
	return eq;
}






