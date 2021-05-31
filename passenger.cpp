#include <iostream>
#include "passenger.h"

using namespace std;

void Passenger::outPassenger() {
	cout << "Имя: " << name;
	cout << ", Возраст: " << age;
	cout << ", Рейс №: " << train_number;
	cout << ", Время отправления: " << time_ot;
	cout << ", Время прибытия: " << time_ot;
	if(spot == 0) {
                 	cout << ", Купе";
	}
	else {
                    	cout << ", Плацкарт";
	}
	cout << ", Номер вагона: " << n_vagona;
	cout << ", Номер места: " << n_mesta;
	cout << ", Пункт отправления: " << city_from;
	cout << ", Пункт назначения: " << city_to;
	cout << ", Состояние: ";
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
