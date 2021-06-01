#include <iostream>
#include <string>
#include <fstream>
#include "classes.h"

using namespace std;

void Train::outTrain() {
cout << "Номер рейса: " << number<<"\n";
cout << "Скорость: " << speed<<"\n";
cout << "Пункт отбытия: " << from<<"\n";
cout << "Пунк прибытия: " << to<<"\n";
cout << "Растояние: " << distance<<"\n";
cout << "Время отбытия: " << t_otb<<"\n";
cout << "Время прибытия: " << t_prib<<"\n";
cout << "Время в пути: " << t_puti<<"\n";
cout << "Вместимость купе: " << capacity_kupe<<"\n";
cout << "Вместимость плацкарта: " << capacity_plackart<<"\n";
cout << "Количество вагонов купе: " << vagoni_kupe<<"\n";
cout << "Количество вагонов плацкарт: " << vagoni_plackart<<"\n";
cout << "Стоимоть купе: " << cost_kupe<<"\n";
cout << "Стоимоть плацкарта: " << cost_plackart << endl<<"\n";
}
