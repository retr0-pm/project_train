#include <iostream>
#include <fstream>
#include <string>
#include "menu.h"

using namespace std;

int main(int argc, char *argv[]) {
	if(argc != 5) {
		cout << "Выберите с чем хотите работать:" << endl;
		cout << "1 - База данный городов" << endl;
		cout << "2 - База данных рейсов" << endl;
		cout << "3 - База данных пассажиров" << endl;
		cout << "4 - Глобальное время" << endl;
		return 1;
	}

	Core fortune(argv[1],argv[2],argv[3],argv[4]);
	if(!fortune.isitokay()) {
		cout << "Программа не может его открыть :'(" << endl;
		return 2;
	}

	Menu ura;
	ura.Start(fortune);

	return 0;
}
