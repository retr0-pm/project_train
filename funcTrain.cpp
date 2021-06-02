#include <iostream>
#include <fstream>
#include <string>
#include "core.h"

using namespace std;

void Core::addTrain() {

	if(sizeC < 2) {
		cout << "Недостаточное количество городов" << endl;
		return;
	}

	Train tr;

	cout << "Введите информацию об этом рейсе: " << endl;

	while(true){
		int buf_;
		bool flag = true;
		cout << "Номер рейса: ";
		cin >> buf_;
		cout << endl;
		for(int i = 0; i < sizeT; i++) {
			if(buf_ == arrTrain[i].get_train_number()){
				flag = false;
			}
		}
		if(flag) {
			tr.set_train_number(buf_);
			break;
		}
		else {
			cout << "Этот номер уже существует. Пожалуйста, попробуйте еще раз." << endl;
		}
	}

        while(true){
                float buf_;
                cout << "Скорость: ";
                cin >> buf_;
		cout << endl;
                if(buf_ > 0) {
                        tr.set_train_speed(buf_);
                        break;
                }
                else {
                        cout << "Скорость должна быть больше нуля" << endl;
                }
        }

	cin.get();
        while(true){
                string buf_;
                bool flag = true;
                cout << "Пункт отправления: " << endl;
                getline(cin,buf_);
                for(int i = 0; i < sizeC; i++) {
                        if(buf_ == arrCity[i].get_city_name()){
                                flag = false;
                        }
		}
                if(!flag) {
                        tr.set_train_from(buf_);
                        break;
                }
                else {
                        cout << "Эта точка не существует. Пожалуйста, попробуйте еще раз." << endl;
                }
        }
        while(true){
                string buf_;
                bool flag = true;
                cout << "Пункт прибытия: " << endl;
                getline(cin,buf_);
                for(int i = 0; i < sizeC; i++) {
                        if(buf_ == arrCity[i].get_city_name()){
                                flag = false;
                        }
		}
                if(!flag) {
                        tr.set_train_to(buf_);
                        break;
                }
                else {
                        cout << "Эта точка не существует. Пожалуйста, попробуйте еще раз." << endl;
                }
        }

	int buf_h, buf_m;
        while(true) {
		cout << "Время отправления (часы): ";
		cin >> buf_h;
		cout << endl;
		if((buf_h < 24) && (buf_h >= 0)) {
			break;
		}
		else {
			cout << "Ввод некорректен. Пожалуйста, попробуйте еще раз." << endl;
		}
	}
	while(true) {
		cout << "Время отправления (минуты): ";
		cin >> buf_m;
		cout << endl;
                if((buf_m < 60) && (buf_m >= 0)) {
                        break;
                }
                else {
                        cout << "Ввод некорректен. Пожалуйста, попробуйте еще раз." << endl;
                }
	}

	Time bufff;
	bufff.set_h(buf_h);
	bufff.set_m(buf_m);

	tr.set_time_otb(bufff);

	tr = calcTime(tr);

        while(true) {
		int buf_;
                cout << "Количество вагонов купе: ";
                cin >> buf_;
                cout << endl;
                if(buf_ > 0) {
			tr.set_train_vagoni_kupe(buf_);
                        break;
                }
                else {
                        cout << "Ввод некорректен. Пожалуйста, попробуйте еще раз." << endl;
                }
	}

        while(true) {
	        int buf_;
                cout << "Количество вагонов плацкарт: ";
                cin >> buf_;
                cout << endl;
                if(buf_ > 0) {
                        tr.set_train_vagoni_plackart(buf_);
                        break;
                }
                else {
                        cout << "Ввод некорректен. Пожалуйста, попробуйте еще раз." << endl;
                }
        }

        while(true) {
                int buf_;
                cout << "Вместительность купе: ";
                cin >> buf_;
                cout << endl;
                if(buf_ > 0) {
                        tr.set_capacity_kupe(buf_);
                        break;
                }
                else {
                        cout << "Ввод некорректен. Пожалуйста, попробуйте еще раз." << endl;
                }
        }

        while(true) {
                int buf_;
                cout << "Вместительность плацкарта: ";
                cin >> buf_;
                cout << endl;
                if(buf_ > 0) {
                        tr.set_capacity_plackart(buf_);
                        break;
                }
                else {
                        cout << "Ввод некорректен. Пожалуйста, попробуйте еще раз." << endl;
                }
        }

        while(true) {
                int buf_;
                cout << "Цена купе: ";
                cin >> buf_;
                cout << endl;
                if(buf_ > 0) {
                        tr.set_train_cost_kupe(buf_);
                        break;
                }
                else {
                        cout << "Ввод некорректен. Пожалуйста, попробуйте еще раз." << endl;
                }
        }

        while(true) {
                int buf_;
                cout << "Цена плацкарта: ";
                cin >> buf_;
                cout << endl;
                if(buf_ > 0) {
                        tr.set_train_cost_plackart(buf_);
                        break;
                }
                else {
                        cout << "Ввод некорректен. Пожалуйста, попробуйте еще раз." << endl;
                }
        }

	ofstream f;
	f.open(fTrain);
	for(int i = 0; i < sizeT; i++) {
		f << arrTrain[i];
	}
	f << tr;
}

void Core::removeTrain() { //udalenie po nomeru marshruta, vizov cherez while(obj.removeTrain())
	if(sizeT == 0) {
		cout << "База данных рейсов пуста" << endl;
		return;
	}

	int buf_;
	bool flag = false;
	cout << "Введите номер рейса";
	cin >> buf_;
	cout << endl;

	for(int i = 0; i < sizeT; i++) {
		if(arrTrain[i].get_train_number() == buf_) {
			flag = true;
			break;
		}
	}
	if(!flag) {
		cout << "Рейса с таки номером нет" << endl;
		return;
	}

	for(int i = 0; i < sizeP; i++) {
		if((arrPassenger[i].get_condition() < 2) && (arrPassenger[i].get_train_number())) {
			flag = false;
			break;
		}
	}
	if(!flag) {
		cout << "Вы не можите удалить этот рейс. Попробуйте позже" << endl;
		return;
	}

	ofstream f;
	f.open(fPassenger);
	for(int i = 0; i < sizeP; i++) {
		if(arrPassenger[i].get_train_number() != buf_) {
			f << arrPassenger[i];
		}
	}
	f.close();

	f.open(fTrain);
        for(int i = 0; i < sizeT; i++) {
                if(arrTrain[i].get_train_number() != buf_) {
                        f << arrTrain[i];
                }
        }
	f.close();
}

void Core::changeTrain() { //Change of direction by number of direction
	if(sizeT == 0) {
		cout << "База данных рейсов пуста" << endl;
		return;
	}

        int buff;
        bool flag = false;
        cout << "Введите номер рейса: ";
        cin >> buff;
        cout << endl;

        for(int i = 0; i < sizeT; i++) {
                if(arrTrain[i].get_train_number() == buff) {
                        flag = true;
			break;
                }
        }
        if(!flag) {
                cout << "Рейса с таким номером нет" << endl;
                return;
        }

        for(int i = 0; i < sizeP; i++) {
                if((arrPassenger[i].get_condition() < 2) && (arrPassenger[i].get_train_number())) {
                        flag = false;
                        break;
                }
        }
        if(!flag) {
                cout << "Вы не можите изменить этот рейс. Попробуйте позже" << endl;
                return;
        }

	Train tr;

	cout << "Введите новую информацию об этом рейсе:" << endl;

	while(true){
		int buf_;
		bool flag = true;
		cout << "Номер рейса: ";
		cin >> buf_;
		cout << endl;
		if(buf_ != buff){
			for(int i = 0; i < sizeT; i++) {
				if(buf_ == arrTrain[i].get_train_number()){
					flag = false;
				}
			}
		}
		if(flag) {
			tr.set_train_number(buf_);
			break;
		}
		else {
			cout << "Такой номер занят. Поробуйте еще раз" << endl;
		}
	}

        while(true){
                float buf_;
                cout << "Скорость: ";
                cin >> buf_;
		cout << endl;
                if(buf_ > 0) {
                        tr.set_train_speed(buf_);
                        break;
                }
                else {
                        cout << "Скороть должна быть больше 0" << endl;
                }
        }

	cin.get();
        while(true){
                string buf_;
                bool flag = true;
                cout << "Пунк отправления: " << endl;
                getline(cin,buf_);
		cout << endl;
                for(int i = 0; i < sizeC; i++) {
                        if(buf_ == arrCity[i].get_city_name()){
                                flag = false;
                        }
		}
                if(!flag) {
                        tr.set_train_from(buf_);
                        break;
                }
                else {
                        cout << "Такого города нет в базе данных. Попробуйте еще раз" << endl;
                }
        }

        while(true){
                string buf_;
                bool flag = true;
                cout << "Пунк прибытия: " << endl;
                getline(cin,buf_);
                cout << endl;
                for(int i = 0; i < sizeC; i++) {
                        if(buf_ == arrCity[i].get_city_name()){
                                flag = false;
                        }
                }
                if(!flag) {
                        tr.set_train_to(buf_);
                        break;
                }
                else {
                        cout << "Такого города нет в базе данных или города поторяются. Попробуйте еще раз" << endl;
                }
        }


	int buf_h, buf_m;
        while(true) {
		cout << "Часы отправления: ";
		cin >> buf_h;
		cout << endl;
		if((buf_h < 24) && (buf_h >= 0)) {
			break;
		}
		else {
			cout << "Ввод некорректен. Пожалуйста, попробуйте еще раз." << endl;
		}
	}

	while(true) {
		cout << "Минуты отправления: ";
		cin >> buf_m;
		cout << endl;
                if((buf_m < 60) && (buf_m >= 0)) {
                        break;
                }
                else {
                        cout << "Ввод некорректен. Пожалуйста, попробуйте еще раз." << endl;
                }
	}

        Time bufff;
        bufff.set_h(buf_h);
        bufff.set_m(buf_m);
        tr.set_time_otb(bufff);

	tr = calcTime(tr);

        while(true) {
		int buf_;
                cout << "Количество вагонов купе: ";
                cin >> buf_;
                cout << endl;
                if(buf_ > 0) {
			tr.set_train_vagoni_kupe(buf_);
                        break;
                }
                else {
                        cout << "Ввод некорректен. Пожалуйста, попробуйте еще раз." << endl;
                }
	}

        while(true) {
	        int buf_;
                cout << "Количество вагонов плацкарт: ";
                cin >> buf_;
                cout << endl;
                if(buf_ > 0) {
                        tr.set_train_vagoni_plackart(buf_);
                        break;
                }
                else {
                        cout << "Ввод некорректен. Пожалуйста, попробуйте еще раз." << endl;
                }
        }

        while(true) {
                int buf_;
                cout << "Вместительность купе: ";
                cin >> buf_;
                cout << endl;
                if(buf_ > 0) {
                        tr.set_capacity_kupe(buf_);
                        break;
                }
                else {
                        cout << "Ввод некорректен. Пожалуйста, попробуйте еще раз." << endl;
                }
        }

        while(true) {
                int buf_;
                cout << "Вместительность плацкарта: ";
                cin >> buf_;
                cout << endl;
                if(buf_ > 0) {
                        tr.set_capacity_plackart(buf_);
                        break;
                }
                else {
                        cout << "Ввод некорректен. Пожалуйста, попробуйте еще раз." << endl;
                }
        }

        while(true) {
                int buf_;
                cout << "Цена купе: ";
                cin >> buf_;
                cout << endl;
                if(buf_ > 0) {
                        tr.set_train_cost_kupe(buf_);
                        break;
                }
                else {
                        cout << "Ввод некорректен. Пожалуйста, попробуйте еще раз." << endl;
                }
        }

        while(true) {
                int buf_;
                cout << "цена плацкарта: ";
                cin >> buf_;
                cout << endl;
                if(buf_ > 0) {
                        tr.set_train_cost_plackart(buf_);
                        break;
                }
                else {
                        cout << "Ввод некорректен. Пожалуйста, попробуйте еще раз." << endl;
                }
        }

	ofstream f;
	f.open(fTrain);
	for(int i = 0; i < sizeT; i++) {
		if(arrTrain[i].get_train_number() == buff) {
			f << tr;
		}
		else {
			f << arrTrain[i];
		}
	}
	f.close();

	f.open(fPassenger);
        for(int i = 0; i < sizeP; i++) {
                if(arrPassenger[i].get_train_number() != buff) {
			arrPassenger[i].outPassenger();// deb
                        f << arrPassenger[i];
                }
                else {
			cout << "Этот человек будет удален из базы даннх пассажиров - ";
			arrPassenger[i].outPassenger();
                }
        }
	f.close();
}

void Core::outputTrain() {
	cout << "Список рейсов:" << endl;
	for(int i = 0; i < sizeT; i++) {
		arrTrain[i].outTrain();
	}
}

void Core::searchTrainNumber() {
	cout << "Введите номер рейса: ";
	int buf_;
	bool flag = false;
	cin >> buf_;
	cout << endl;
	for(int i = 0; i < sizeT; i++) {
		if(buf_ == arrTrain[i].get_train_number()) {
			arrTrain[i].outTrain();
			flag = true;
			break;
		}
	}
	if(!flag) {
		cout << "Рейса с таким номером нет" << endl;
	}
}

void Core::searchTrainPoint() {
	cin.get();
        cout << "Введите пункт отбытия: " << endl;
        string bufFrom;
        getline(cin,bufFrom);
        cout << endl;
        cout << "Введите пункт прибытия: " << endl;
        string bufTo;
        getline(cin,bufTo);
        cout << endl;

	bool flag = false;
        for(int i = 0; i < sizeT; i++) {
                if((bufFrom == arrTrain[i].get_train_city_from()) && (bufTo == arrTrain[i].get_train_city_to())) {
			arrTrain[i].outTrain();
			flag = true;
                        break;
                }
        }
        if(!flag) {
                cout << "Рейса между этими городами нет" << endl;
        }
}
