#include "../includes/Scanner.h"
#include "../includes/Token.h"
#include "../../Util/String/String.cpp"
#include <iostream>

Scanner::Scanner(char* fileName) {
    std::cout << "[SCANNER CONSTRUCTOR] : " << this << std::endl;

    this->automat = new Automat();
    this->buffer = new Buffer(fileName);
    this->symboltable = new Symboltable();

}

Scanner::~Scanner() {
	delete automat;
	delete buffer;
	delete symboltable;
}


Token* Scanner::getToken() {

    int line;
    int column;
    bool legal;
    String lexem('a');
    lexem -= 1;
    TokenType lastValidTokenType;

    do {

        line = buffer->getLine();
        column = buffer->getColumn();
        char c = buffer->getChar();

        // check EOF
        if (c == '\0') {
            if (lexem.length > 0) return new Token(lastValidTokenType, line, column);
            return nullptr;

        }

        legal = automat->step(c);

        //std::cout << "[SCANNER] " << "c: " << c << std::endl;
        //std::cout << "[SCANNER] " << "legal: " << legal << std::endl;
        //std::cout << "[SCANNER] " << "lexem length: " << lexem.length << std::endl;

        if (legal) {
            lexem += c;
            lastValidTokenType = automat->getTokenType();
        } else if (lexem.length > 0) {
            if (automat->getTokenType() == COMMENT_START) {

                // run to end of comment
                char lastChar = c;
        while (!(c == ':' && lastChar == '*') && c != '\0') {
            lastChar = c;
            c = buffer->getChar();
        }
                automat->reset();
                legal = true;

            } else {

                // build token
                Token* token;
                if (lastValidTokenType == IDENTIFIER) {
                    SymtabEntry* key = symboltable->insert(lexem.get(), automat->getTokenType());
                    token = new Token(lastValidTokenType, line, column, key);
                } else if (lastValidTokenType == INTEGER) {
                    // int value = lexem.parseInt(); diese Methode existiert in String nicht
                	int value = 0; //testwert
                    token = new Token(lastValidTokenType, line, column, value);
                } else {
                    token = new Token(lastValidTokenType, line, column);
                }

                // reset
                automat->reset();
                buffer->ungetChar();
                lexem -= lexem.length - 1;

                return token;
            }
        } else {
            automat->reset();
            return new Token(line, column, c);
        }

    } while(legal);

    Token* token = new Token(lastValidTokenType, line, column);
    automat->reset();
    lexem -= lexem.length - 1;

    return token;
}


Symboltable* Scanner::getSymboltable() {

    return symboltable;
}

