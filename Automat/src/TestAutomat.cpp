#include <iostream>
using namespace std;
#include "../includes/Automat.h"
#include "../../Scanner/includes/TokenType.h"

int main() {

	Automat* automat = new Automat();
	cout << "Testoooooo" << endl;
	automat->step(':');
	cout << automat->getTokenType() << endl;
	automat->step('=');
	cout << automat->getTokenType() << endl;
	automat->reset();

	automat->step('a');
	automat->step('0');
	cout <<"after id+integer "<< automat->getTokenType() << endl;
	automat->step('Z');
	cout <<"meep "<< automat->getTokenType() << endl;
	automat->reset();

	automat->step('=');
	automat->getTokenType();
	automat->step(':');
	automat->getTokenType();
	automat->step('=');
	automat->getTokenType();
	automat->reset();
	int a = 5;
	cout<<a<<endl;
	automat->step('&');

	cout << automat->getTokenType() << endl;
	automat->step('b');
	cout << automat->getTokenType() << endl;
	automat->step('&');
	cout << automat->getTokenType() << endl;
	automat->reset();

	automat->step('i');
	cout <<"before SPACE  "<< automat->getTokenType() << endl;
	automat->step(' ');
	cout <<"after SPACE   "<< automat->getTokenType() << endl;
	automat->step('F');
	cout << automat->getTokenType() << endl;
	automat->reset();

	automat->step(':');
		cout <<": / 3   "<< automat->getTokenType() << endl;
		automat->step('*');
		cout <<"* / comment_start "<< automat->getTokenType() << endl;
		automat->step('F');
		cout << automat->getTokenType() << endl;
		automat->step(' ');
		cout <<"space   "<< automat->getTokenType() << endl;
		automat->step('*');
		cout <<"* / star "<< automat->getTokenType() << endl;
		automat->step(':');
		cout <<": / 8   "<< automat->getTokenType() << endl;
		cout <<"comment_end  "<<automat->getTokenType() << endl;
		automat->reset();
		automat->step(' ');
				cout <<"space   "<< automat->getTokenType() << endl;


	delete automat;
	cout << "Test" << endl;
	std::cin.get();

	return 0;
}

