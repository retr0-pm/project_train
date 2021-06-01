#include <iostream>
#include <fstream>
#include <string>
#include "core.h"

using namespace std;

void Core::addTrain() {

	if(sizeC < 2) {
		cout << "Not enought points" << endl;
		return;
	}

	Train tr;

	cout << "Enter info about this route:" << endl;

	while(true){
		int buf_;
		bool flag = true;
		cout << "Number of the route: ";
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
			cout << "This number already exist. Please try again" << endl;
		}
	}

        while(true){
                float buf_;
                cout << "Speed: ";
                cin >> buf_;
		cout << endl;
                if(buf_ > 0) {
                        tr.set_train_speed(buf_);
                        break;
                }
                else {
                        cout << "The speed must be over than 0" << endl;
                }
        }

	cin.get();
        while(true){
                string buf_;
                bool flag = true;
                cout << "Sending point: " << endl;
                getline(cin,buf_);
		cout << buf_ << endl;
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
                        cout << "This point doesn't exist. Please try again" << endl;
                }
        }

        while(true){
                string buf_;
                bool flag = true;
                cout << "Kuda edet: " << endl;
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
                        cout << "This point doesn't exist. Please try again" << endl;
                }
        }

	int buf_h, buf_m;
        while(true) {
		cout << "Departure Hour: ";
		cin >> buf_h;
		cout << endl;
		if((buf_h < 24) && (buf_h >= 0)) {
			break;
		}
		else {
			cout << "Incorrect input. Please try again" << endl;
		}
	}
	while(true) {
		cout << "Departure Minute: ";
		cin >> buf_m;
		cout << endl;
                if((buf_m < 60) && (buf_m >= 0)) {
                        break;
                }
                else {
                        cout << "Incorrect input. Please try again" << endl;
                }
	}

	Time bufff;
	bufff.set_h(buf_h);
	bufff.set_m(buf_m);

	tr.set_time_otb(bufff);

	tr = calcTime(tr);

        while(true) {
		int buf_;
                cout << "Numbers of cars kupe: ";
                cin >> buf_;
                cout << endl;
                if(buf_ > 0) {
			tr.set_train_vagoni_kupe(buf_);
                        break;
                }
                else {
                        cout << "Incorrect input. Please try again" << endl;
                }
	}

        while(true) {
	        int buf_;
                cout << "Numbers of cars plackart: ";
                cin >> buf_;
                cout << endl;
                if(buf_ > 0) {
                        tr.set_train_vagoni_plackart(buf_);
                        break;
                }
                else {
                        cout << "Incorrect input. Please try again" << endl;
                }
        }

        while(true) {
                int buf_;
                cout << "Cupe capacity: ";
                cin >> buf_;
                cout << endl;
                if(buf_ > 0) {
                        tr.set_capacity_kupe(buf_);
                        break;
                }
                else {
                        cout << "Incorrect input. Please try again" << endl;
                }
        }

        while(true) {
                int buf_;
                cout << "Plackart capacity: ";
                cin >> buf_;
                cout << endl;
                if(buf_ > 0) {
                        tr.set_capacity_plackart(buf_);
                        break;
                }
                else {
                        cout << "Incorrect input. Please try again" << endl;
                }
        }

        while(true) {
                int buf_;
                cout << "Cost kupe: ";
                cin >> buf_;
                cout << endl;
                if(buf_ > 0) {
                        tr.set_train_cost_kupe(buf_);
                        break;
                }
                else {
                        cout << "Incorrect input. Please try again" << endl;
                }
        }

        while(true) {
                int buf_;
                cout << "Cost plackart: ";
                cin >> buf_;
                cout << endl;
                if(buf_ > 0) {
                        tr.set_train_cost_plackart(buf_);
                        break;
                }
                else {
                        cout << "Incorrect input. Please try again" << endl;
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
		cout << "The list of directions is empty" << endl;
		return;
	}

	int buf_;
	bool flag = false;
	cout << "Enter the number of the direction: ";
	cin >> buf_;
	cout << endl;

	for(int i = 0; i < sizeT; i++) {
		if(arrTrain[i].get_train_number() == buf_) {
			flag = true;
			break;
		}
	}
	if(!flag) {
		cout << "This number of the direction doesn't exist" << endl;
		return;
	}

	for(int i = 0; i < sizeP; i++) {
		if((arrPassenger[i].get_condition() < 2) && (arrPassenger[i].get_train_number())) {
			flag = false;
			break;
		}
	}
	if(!flag) {
		cout << "This route is used by passengers right now. Try do this later" << endl;
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
                        f << arrPassenger[i];
                }
        }
	f.close();
}

void Core::changeTrain() { //Change of direction by number of direction
	if(sizeT == 0) {
		cout << "The list of directions is empty" << endl;
		return;
	}

        int buff;
        bool flag = false;
        cout << "Enter the number of the direction: ";
        cin >> buff;
        cout << endl;

        for(int i = 0; i < sizeT; i++) {
                if(arrTrain[i].get_train_number() == buff) {
                        flag = true;
			break;
                }
        }
        if(!flag) {
                cout << "This number of the direction doesn't exist" << endl;
                return;
        }

        for(int i = 0; i < sizeP; i++) {
                if((arrPassenger[i].get_condition() < 2) && (arrPassenger[i].get_train_number())) {
                        flag = false;
                        break;
                }
        }
        if(!flag) {
                cout << "This route is used by passengers right now. Try do this later" << endl;
                return;
        }

	Train tr;

	cout << "Enter new info about this direction:" << endl;

	while(true){
		int buf_;
		bool flag = true;
		cout << "Number of the route: ";
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
			cout << "This number already exist. Please try again" << endl;
		}
	}

        while(true){
                float buf_;
                cout << "Speed: ";
                cin >> buf_;
		cout << endl;
                if(buf_ > 0) {
                        tr.set_train_speed(buf_);
                        break;
                }
                else {
                        cout << "The speed must be over than 0" << endl;
                }
        }

        while(true){
                string buf_;
                bool flag = true;
                cout << "Sending point: " << endl;
		cin.get();
                getline(cin,buf_);
		cout << endl;
                for(int i = 0; i < sizeC; i++) {
                        if(buf_ == arrCity[i].get_city_name()){
                                flag = false;
                        }
		}
                if(flag) {
                        tr.set_train_from(buf_);
                        break;
                }
                else {
                        cout << "This point doesn't exist. Please try again" << endl;
                }
        }

        while(true){
                string buf_;
                bool flag = true;
                cout << "Kuda edet: " << endl;
		cin.get();
                getline(cin,buf_);
                cout << endl;
                for(int i = 0; i < sizeC; i++) {
                        if(buf_ == arrCity[i].get_city_name()){
                                flag = false;
                        }
                }
                if(flag) {
                        tr.set_train_to(buf_);
                        break;
                }
                else {
                        cout << "This point doesn't exist. Please try again" << endl;
                }
        }


	int buf_h, buf_m;
        while(true) {
		cout << "Departure Hour: ";
		cin >> buf_h;
		cout << endl;
		if((buf_h < 24) && (buf_h >= 0)) {
			break;
		}
		else {
			cout << "Incorrect input. Please try again" << endl;
		}
	}

	while(true) {
		cout << "Departure Minute: ";
		cin >> buf_m;
		cout << endl;
                if((buf_m < 60) && (buf_m >= 0)) {
                        break;
                }
                else {
                        cout << "Incorrect input. Please try again" << endl;
                }
	}

        Time bufff;
        bufff.set_h(buf_h);
        bufff.set_m(buf_m);
        tr.set_time_otb(bufff);

	tr = calcTime(tr);

        while(true) {
		int buf_;
                cout << "Numbers of cars kupe: ";
                cin >> buf_;
                cout << endl;
                if(buf_ > 0) {
			tr.set_train_vagoni_kupe(buf_);
                        break;
                }
                else {
                        cout << "Incorrect input. Please try again" << endl;
                }
	}

        while(true) {
	        int buf_;
                cout << "Numbers of cars plackart: ";
                cin >> buf_;
                cout << endl;
                if(buf_ > 0) {
                        tr.set_train_vagoni_plackart(buf_);
                        break;
                }
                else {
                        cout << "Incorrect input. Please try again" << endl;
                }
        }

        while(true) {
                int buf_;
                cout << "Cupe capacity: ";
                cin >> buf_;
                cout << endl;
                if(buf_ > 0) {
                        tr.set_capacity_kupe(buf_);
                        break;
                }
                else {
                        cout << "Incorrect input. Please try again" << endl;
                }
        }

        while(true) {
                int buf_;
                cout << "Plackart capacity: ";
                cin >> buf_;
                cout << endl;
                if(buf_ > 0) {
                        tr.set_capacity_plackart(buf_);
                        break;
                }
                else {
                        cout << "Incorrect input. Please try again" << endl;
                }
        }

        while(true) {
                int buf_;
                cout << "Cost kupe: ";
                cin >> buf_;
                cout << endl;
                if(buf_ > 0) {
                        tr.set_train_cost_kupe(buf_);
                        break;
                }
                else {
                        cout << "Incorrect input. Please try again" << endl;
                }
        }

        while(true) {
                int buf_;
                cout << "Cost plackart: ";
                cin >> buf_;
                cout << endl;
                if(buf_ > 0) {
                        tr.set_train_cost_plackart(buf_);
                        break;
                }
                else {
                        cout << "Incorrect input. Please try again" << endl;
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
                        f << arrPassenger[i];
                }
                else {
			cout << "This person will be removed from the list of passengers - ";
			arrPassenger[i].outPassenger();
                }
        }
	f.close();
}

void Core::outputTrain() {
	cout << "The list of the directions:" << endl;
	for(int i = 0; i < sizeT; i++) {
		arrTrain[i].outTrain();
	}
}

void Core::searchTrainNumber() {
	cout << "Enter the number of the direction: ";
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
		cout << "The direction with this number doesn't exist" << endl;
	}
}

void Core::searchTrainPoint() {
        cout << "Enter the point from: " << endl;
        string bufFrom;
	cin.get();
        getline(cin,bufFrom);
        cout << endl;
        cout << "Enter the point to: " << endl;
        string bufTo;
	cin.get();
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
                cout << "The direction with this points doesn't exist" << endl;
        }
}
