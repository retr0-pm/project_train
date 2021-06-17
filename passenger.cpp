#include <iostream>
#include <string>
#include <fstream>
#include "passenger.h"

using namespace std;

void Passenger::outPassenger() {
	cout << "Имя: " << name<<"\n";
	cout << "Возраст: " << age<<"\n";
	cout << "Рейс №: " << train_number<<"\n";
	cout << "Время отправления: " << time_ot<<"\n";
	cout << "Время прибытия: " << time_prib<<"\n";
	if(spot == 0) {
                 	cout << "Купе"<<"\n";
	}
	else {
                    	cout << "Плацкарт"<<"\n";
	}
	cout << "Номер вагона: " << n_vagona<<"\n";
	cout << "Номер места: " << n_mesta<<"\n";
	cout << "Пункт отправления: " << city_from<<"\n";
	cout << "Пункт назначения: " << city_to<<"\n";
	cout << "Состояние: ";
	switch(condition) {
		case 0:
			cout << "Ожидает" << endl;
			break;
		case 1:
			cout << "В пути" << endl;
			break;
		case 2:
			cout << "Приехал" << endl;
			break;
	}
}
