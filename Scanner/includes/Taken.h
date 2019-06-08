/*
 * Taken.h
 *
 *  Created on: 26.05.2019
 *      Author: yue
 */

#ifndef SCANNER_SRC_TAKEN_H_
#define SCANNER_SRC_TAKEN_H_



class Taken
{
private:

	int mLine, mColumn;

public:
	Taken(int line, int column);

	~Taken();

	void print();


	int getLine() {
		return mLine;
	}
	int getColumn() {
		return mColumn;
	}

};




#endif /* SCANNER_SRC_TAKEN_H_ */
