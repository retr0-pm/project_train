#include <iostream>
#include <fstream>
#include <string>
#include "core.h"

using namespace std;

void Core::addCity() {
	City bufC;

	while(true){
		cout << "Введите название пункта: " << endl;
		string buf_;
		bool flag_ = true;
		cin.get();
		getline(cin,buf_,'\n');
		for(int i = 0; i < sizeC; i++) {
			if(arrCity[i].get_city_name() == buf_) {
				flag_ = false;
				break;
			}
		}
		if(flag_) {
			bufC.set_city_name(buf_);
			break;
		}
		else {
			cout << "Пункт с таким названием уже существует. Пожалуйста, попробуйте ещё раз" << endl;
		}
	}

	float a,b;
	cout << "Введите координаты в формате x y: ";
	cin >> a >> b;
	cout << endl;
	bufC.set_coordinates(a,b);

	ofstream f;
	f.open(fCity);
	for (int i = 0; i < sizeC; i++) {
		f << arrCity[i];
	}
	f << bufC;
	f.close();

}

void Core::removeCity() {
	if(sizeC < 1) {
		cout << "База данных пунктов пуста" << endl;
		return;
	}

	string buf_;
	cout << "Введите название пункта:" << endl;
	cin.get();
	getline(cin,buf_);
	cout << endl;

	bool flag_ = false;
	for (int i = 0; i < sizeC; i++) {
		if(buf_ == arrCity[i].get_city_name()) {
			flag_ = true;
			break;
		}
	}
	if(!flag_) {
		cout << "Данного пункта нет в базе данных" << endl;
		return;
	}

	for(int i = 0; i < sizeP; i++) {
		if((arrPassenger[i].get_condition() < 2) && ((arrPassenger[i].get_city_from() == buf_) || (arrPassenger[i].get_city_to() == buf_))) {
			flag_ = false;
			break;
		}
	}
	if(!flag_) {
		cout << "Вы не можете удалить этот пункт сейчас. Попробуйте позже." << endl;
		return;
	}

	ofstream f;
	f.open(fCity);
	for(int i = 0; i < sizeC; i++) {
		if(arrCity[i].get_city_name() != buf_) {
			f << arrCity[i];
		}
	}
	f.close();

	f.open(fTrain);
	for(int i = 0; i < sizeT; i++) {
		if((arrTrain[i].get_train_city_from() != buf_) && (arrTrain[i].get_train_city_to() != buf_)) {
			f << arrTrain[i];
		}
		else {
			cout << "Этот рейс будет удален - ";
			arrTrain[i].outTrain();
		}
	}
	f.close();

	for (int i = 0; i < sizeP; i++) {
                if((arrPassenger[i].get_city_from() != buf_) && (arrPassenger[i].get_city_to() != buf_)) {
                        f << arrTrain[i];
                }
                else {
			cout << "Этот человек будет удален из списка пассажиров - ";
			arrPassenger[i].outPassenger();
		}
	}
	f.close();

	return;
}

void Core::changeCity() {
        if(sizeC < 1) {
                cout << "База данных городов пунктов" << endl;
                return;
        }

        string buf_;
        cout << "Введите название пункта:" << endl;
	cin.get();
        getline(cin,buf_);
        cout << endl;

        bool flag_ = false;
        for (int i = 0; i < sizeC; i++) {
                if(buf_ == arrCity[i].get_city_name()) {
                        flag_ = true;
                        break;
                }
        }
        if(!flag_) {
                cout << "Данного пункта нет в базе данных" << endl;
                return;
        }

        for(int i = 0; i < sizeP; i++) {
                if((arrPassenger[i].get_condition() < 2) && ((arrPassenger[i].get_city_from() == buf_) || (arrPassenger[i].get_city_to() == buf_))) {
                        flag_ = false;
                        break;
                }
        }
        if(!flag_) {
                cout << "Вы не можете изменить этот пункт сейчас. Попробуйте позже." << endl;
                return;
        }

        City bufC;
        while(true){
                cout << "Введите новое название: " << endl;
                string buff;

                getline(cin,buff);
		if(buff != buf_) {
                	for(int i = 0; i < sizeC; i++) {
                        	if(arrCity[i].get_city_name() == buff) {
                                	flag_ = false;
                                	break;
                        	}
                	}
		}
                if(flag_) {
                        bufC.set_city_name(buff);
                        break;
                }
                else {
                        cout << "Пункт с таким названием уже существует. Пожалуйста, попробуйте ещё раз" << endl;
                }
        }

        float a,b;
        cout << "Введите координаты в формате x y: ";
        cin >> a >> b;
        cout << endl;
        bufC.set_coordinates(a,b);

	ofstream f;
	f.open(fCity);
	for(int i = 0; i < sizeC; i++) {
		if(arrCity[i].get_city_name() == buf_) {
			f << bufC;
		}
		else {
			f << arrCity[i];
		}
	}
	f.close();

        f.open(fTrain);
        for(int i = 0; i < sizeT; i++) {
                if((arrTrain[i].get_train_city_from() != buf_) && (arrTrain[i].get_train_city_to() != buf_)) {
                        f << arrTrain[i];
                }
                else {
                        cout << "Этот рейс будет удален - ";
                        arrTrain[i].outTrain();
                }
        }
        f.close();

        for (int i = 0; i < sizeP; i++) {
                if((arrPassenger[i].get_city_from() != buf_) && (arrPassenger[i].get_city_to() != buf_)) {
                        f << arrTrain[i];
                }
                else {
                        cout << "Этот человек будет удален из списка пассажиров - ";
                        arrPassenger[i].outPassenger();
                }
        }
        f.close();

        return;
}

void Core::outputCity() {
	if(sizeC < 1) {
		cout << "Список пунктов пуст" << endl;
		return;
	}

	cout << "Список пунктов: " << endl;
	for(int i = 0; i < sizeC; i++) {
		arrCity[i].outCity();
	}

	return;
}

void Core::searchCity() {
	if(sizeC < 1) {
		cout << "Список пунктов пуст" << endl;
		return;
	}

	cout << "Введите названия пункта: " << endl;
	string buf_;
	bool flag_ = false;
	cin.get();
	getline(cin,buf_);
	cout << endl;
	for(int i = 0; i < sizeC; i++) {
		if(arrCity[i].get_city_name() == buf_) {
			arrCity[i].outCity();
			flag_ = true;
			break;
		}
	}
	if(!flag_) {
		cout << "Пункта с таким названием не найдено" << endl;
	}

	return;
}
