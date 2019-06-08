/*
 * Taken.cpp
 *
 *  Created on: 26.05.2019
 *      Author: yue
 */

#include "../includes/Taken.h"

#include <iostream>
using namespace std;
Taken::Taken( int line, int column) {

	mLine = line;
	mColumn = column;
}
Taken::~Taken() {
 mLine=0;
 mColumn=0;
}
void Taken::print() {
	std::cout << " Line: " << mLine << " Column: " << mColumn;

	std::cout << std::endl;
}




