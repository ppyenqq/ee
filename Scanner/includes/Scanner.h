#ifndef SCANNER_H_
#define SCANNER_H_

#include "../../Automat/includes/Automat.h"
#include "../../Buffer/includes/Buffer.h"
#include "../../Symboltable/includes/Symboltable.h"
#include "Token.h"

class Scanner {
private:
	Automat* automat;
	Buffer* buffer;
	Symboltable* symboltable;
public:
	Scanner(char* fileName);
	virtual ~Scanner();

	Token* getToken();

	Symboltable* getSymboltable();

};

#endif /* SCANNER_H_ */
