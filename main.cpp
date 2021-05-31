#include "menu.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
	if(argc != 4) {
		cout << "Please enter four arguments:" << endl;
		cout << "1 - BD punktov" << endl;
		cout << "2 - BD reisov" << endl;
		cout << "3 - BD passagirov" << endl;
		cout << "4 - fail globalnogo vremeni" << endl;
		return 1;
	}

	Core fortune(argv[1],argv[2],argv[3],argv[4]);
	if(!fortune.isitokay()) {
		cout << "The program can't open this :'(" << endl;
		return 2;
	}

	Menu ura;
	ura.Start(fortune);

	return 0;
}
