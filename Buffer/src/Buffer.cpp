/*
 * Buffer.cpp
 *
 *  Created on: Sep 26, 2012
 *      Author: knad0001
 */

#include "../includes/Buffer.h"
#include <stdexcept>

Buffer::Buffer( char *filename) {

	bufferLength = buffsize;
	sourceFile = filename;
	leftBuffer = new char[bufferLength];
	rightBuffer = new char[bufferLength];

	//speicher für 2 BUffer zuweisen
	posix_memalign((void**) &(this->leftBuffer), buffsize, bufferLength);
	posix_memalign((void**) &(this->rightBuffer), buffsize, bufferLength);
	fRead = 0; //fileDescriptor
	bytesRead = 0; //anzahl in Buffer eingelesene char bzw byteGröße des textfile wenn kleiner als buffsize

	eof = '\0'; //
	leftBufStart = &leftBuffer[0]; //startposition von linkes BUffer
	rightBufStart = &rightBuffer[0];
	next = &leftBuffer[0];
	current = &leftBuffer[0];
	fileIsOpen = false;
	eofReached = false; //ende vom Textfile erreicht
	leftBufActive = true; //wird gerade mit linkes oder rechtes Buffer gearbeitet
	line = 1;
	column = 0;
	lineEndDetected = false;

	openFile();
	fillBuffer();
}

Buffer::~Buffer() {

	close(fRead); //schließ geöffnete Datei
	free(leftBuffer);
	free(rightBuffer);
}

char Buffer::getChar() {
	current = next;


	if (*current == '\0') { //prüfe ob textfile zuende ist, wenn ja schließe alles und gibt '\0' zurück
		cout<<"'\0' erkannt.Ende.Aus."<<endl;
		eofReached = true;
		close(fRead);

		return '\0'; //or return eof
	}
	if (current == rightBufStart + buffsize - 1) {
		//if ende rightBuffer angelangt

		leftBufActive = true;
		fillBuffer(); //fülle linkes Buffer neu
		next = leftBufStart;
		addColumnLine();

		return *current;
	}
	if (current == leftBufStart + buffsize - 1) {
		//if ende leftBuffer angelangt

		leftBufActive = false;
		fillBuffer(); //fülle rechtes Buffer neu
		next = rightBufStart;
		addColumnLine();

		return *current;
	}
	next++;
	addColumnLine();

	return *current;
}

void Buffer::ungetChar() {
	if (current == rightBufStart) { //wenn das currentChar am anfang des Rechten buffer steht

		next = &leftBuffer[buffsize - 1]; //schiebe next zurück auf letzte Platz vom Linken Buffer
		leftBufActive = true;
	} else if (current == leftBufStart) { //wenn das currentChar am anfang des Linken buffer steht

		next = &rightBuffer[buffsize - 1];
		leftBufActive = false;
	} else {

		next--;
	}
	reduceColumnLine();
	current = next;

}
void Buffer::openFile() {
	fRead = open(sourceFile, O_DIRECT);
	if (fRead != -1) {
		fileIsOpen = true;
		cout << "file opened successfully" << endl;
	} else {
		throw std::runtime_error("Not able to open Inputfile");
	}
}
//methode fürs testen im for schleife
bool Buffer::fileEnded() {
	return eofReached;
}
//fülle den Buffer mit chars
void Buffer::fillBuffer() {
	cout << "start Filling" << endl;
	if (leftBufActive) {
		bytesRead = read(fRead, leftBufStart, buffsize);

	} else {
		bytesRead = read(fRead, rightBufStart, buffsize);

	}
}
int Buffer::getLine() {
	return line;

}
int Buffer::getColumn() {
	return column;

}
//verändert line bzw column wenn ende einer Zeile erkannt bzw ein beliebiges char erkannt wurde
void Buffer::addColumnLine() {

	if (*current == '\n') {
		if (lineEndDetected) {

			line++;

			column = 1;

		} else {

			column++;
		}
		lineEndDetected = true;
	} else {
		if (lineEndDetected) {

			line++;
			prevColumn = column;
			column = 1;
			lineEndDetected = false;

		} else {

			column++;
		}

	}

}
void Buffer::reduceColumnLine() {
	if (*current == '\n') {
			if (*current-1=='\n') {

				lineEndDetected=true;//eigtl. überflüssig
				line--;
				column=1;//auch überflüssig

			} else {

				column--;
				lineEndDetected=false;
			}

	} else {
			if (lineEndDetected) {//oder *next=='\n

				line--;
				column =prevColumn ;
//				lineEndDetected = true; überflüssig

			} else {

				column--;
			}

		}


}
