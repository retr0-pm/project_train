#include <string>
#include <cmath>
#include <iostream>
#include <fstream>
#include "core.h"

using namespace std;

void Core::searchPassenger(){
	if(sizeP == 0){cout<<"Список пассажиров пуст"<<endl; return;}
	int a;
	cout<<"1 - поиск по имени. 2 - поиск по номеру рейса. 0 - back" << endl;
	cout << "Ваш выбор: ";
	cin>>a;
	cout << endl;
	int s = 0;
	string buf1_;
	int buf11_;
	switch(a) {
		case 1:
			cout<<"Введите имя: " << endl;
			cin.get();
			getline(cin,buf1_);
			cout << endl;
			for(int i = 0; i < sizeP; i++) {
				if(arrPassenger[i].get_name() == buf1_){
					arrPassenger[i].outPassenger();
					if(arrPassenger[i].get_condition() == 1){
						calcPosition(arrPassenger[i]);
					}
					s++;
					break;
				}
			}
			if(s == 0){cout<<"Ничего не найдено" << endl;}
			break;
		case 2:
			cout<<"Введите номер:";
			cin >> buf11_;
			cout << endl;
			for(int i = 0; i < sizeP; i++) {
				if(arrPassenger[i].get_train_number() == buf11_){
					arrPassenger[i].outPassenger();
					s++;
					if(arrPassenger[i].get_condition() == 1){
						calcPosition(arrPassenger[i]);
					}
				}
			}
			if (s == 0 ){cout<<"Ничего не найдено" << endl;}
			break;
		case 0:
			break;
		default:
			break;
	}
}

void Core::calcPosition(Passenger &t){
	Train buf;
	for(int i=0; i<sizeT; i++){
		if(arrTrain[i].get_train_number() == t.get_train_number()){
			buf = arrTrain[i];
			break;
		}
	}
	City buf1, buf2;
	for(int i=0; i<sizeC; i++){
		if(arrCity[i].get_city_name() == buf.get_train_city_from()){
			buf1 = arrCity[i];
			break;
		}
	}
	for(int i=0; i<sizeC; i++){
		if(arrCity[i].get_city_name() == buf.get_train_city_to()){
			buf2 = arrCity[i];
			break;
		}
	}
	Time t_in_d = gt-t.get_time_ot();
	int minuts1 = TtoM(gt);
	int minuts2 = TtoM(t_in_d);
	float m=((minuts1-minuts2)*sqrt((buf2.get_city_x()-buf1.get_city_x())*(buf2.get_city_x()-buf1.get_city_x())+(buf2.get_city_y()-buf1.get_city_y())*(buf2.get_city_y()-buf1.get_city_y())))/buf.get_train_speed();//koeff. for formula
	float Xx=(buf1.get_city_x()+m*buf2.get_city_x())/(1+m);//final x of time's moment
	float Yy=(buf1.get_city_y()+m*buf2.get_city_y())/(1+m);//final y of time's moment
	cout <<"Координата х на данный момент:"<< Xx << endl;
	cout <<"Координата у на данный момент:"<< Yy << endl;
}

void Core::sizeCity(){
	fstream f;
	f.open(fCity,ios::in);
	int size = 0;
	string b;
	while(f.peek() != EOF){
		getline (f,b);
		size++;
	}
	sizeC=size/3;
	f.close();
} //Opredelenie razmera massiva gorodov
void Core::sizeTrain(){
	fstream f;
	f.open(fTrain,ios::in);
	int size = 0;
	string b;
	while(f.peek() != EOF){
		getline (f,b);
		size++;
	}
	sizeT=size/14;
	f.close();
}  //Opredelenie razmera massiva reisov
void Core::sizePassenger(){
	fstream f;
	f.open(fPassenger,ios::in);
	int size = 0;
	string b;
	while(f.peek() != EOF){
		getline (f,b);
		size++;
	}
	sizeP=size/11;
	f.close();
}  //Opredelenie razmera massiva passagirov

void Core::fArrCity(){
	arrCity = new City[sizeC];
	fstream f;
	f.open(fCity,ios::in);
	for (int i = 0; i < sizeC; i++) {
		f >> arrCity[i];
		f.get();
	}
	f.close();
} //zanesenie iz faila v massiv gorodov
void Core::fArrTrain(){
	arrTrain = new Train[sizeT];
	fstream f;
	f.open(fTrain,ios::in);
	for (int i = 0; i < sizeT; i++) {
		f >> arrTrain[i];
		//f.get();
	}
	f.close();
} //zanesenie iz faila v massiv reisov
void Core::fArrPassenger(){
	arrPassenger = new Passenger [sizeP];
	fstream f;
	f.open(fPassenger,ios::in);
	for (int i = 0; i < sizeP; i++) {
		f >> arrPassenger[i];
		f.get();
	}
	f.close();
} //zanesenie iz faila v massiv passagirov
void Core::getGT(){
	fstream f;
	f.open(fTime,ios::in);
	f >> gt;
	f.close();
} //zanesenie iz faila globalnogo vremeni
void Core::clArrCity(){
	delete [] arrCity;
} //ochistka pamyati massiva gorodov
void Core::clArrTrain(){
	delete [] arrTrain;
}
//ochistka pamyati massiva reisov
void Core::clArrPassenger(){
	delete [] arrPassenger;
} //ochistka pamyati massiva passagirov

Core::Core(char *_fCity, char *_fTrain, char *_fPassenger, char *_fTime) {
	fCity = _fCity;
	fTrain = _fTrain;
	fPassenger = _fPassenger;
	fTime = _fTime;
}

bool Core::isitokay() {
	fstream f;

	f.open(fCity,ios::in);
	if (f) {
		f.close();
	}
	else {
		cout << "Какие-то проблемы с файлом: " << fCity << endl;
		return false;
	}

        f.open(fTrain,ios::in);
        if (f) {
                f.close();
        }
        else {
                cout << "Какие-то проблемы с файлом: " << fTrain << endl;
                return false;
        }

        f.open(fPassenger,ios::in);
        if (f) {
                f.close();
        }
        else {
                cout << "Какие-то проблемы с файлом: " << fPassenger << endl;
                return false;
        }


	bool pust = true;
        f.open(fTime,ios::in);
        if (f) {
		if(f.peek() != EOF) {
			pust = false;
		}
                f.close();
        }
        else {
                cout << "Какие-то проблемы с файлом: " << fTime << endl;
                return false;
        }
	if(pust) {
		f.open(fTime,ios::out);
		f << "0 0 0";
		f.close();
	}

	return true;
}










