#include <iostream>
#include <string>
#include <fstream>
#include "train.h"

using namespace std;

void Train::outTrain() {
cout << "Номер рейса: " << number<<"\n";
cout << "Скорость: " << speed<<"\n";
cout << "Пункт отправления: " << from<<"\n";
cout << "Пунк назначения: " << to<<"\n";
cout << "Растояние: " << distance<<"\n";
cout << "Время отбытия: " << t_otb<<"\n";
cout << "Время прибытия: " << t_prib<<"\n";
cout << "Время в пути: " << t_puti<<"\n";
cout << "Вместимость вагона купе: " << capacity_kupe<<"\n";
cout << "Вместимость вагона плацкарта: " << capacity_plackart<<"\n";
cout << "Количество вагонов купе: " << vagoni_kupe<<"\n";
cout << "Количество вагонов плацкарт: " << vagoni_plackart<<"\n";
cout << "Цена билета купе: " << cost_kupe<<"\n";
cout << "Цена билета плацкарт: " << cost_plackart << endl<<"\n";
}
