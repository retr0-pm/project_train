#include <iostream>
#include <fstream>
#include <string>
#include "core.h"

using namespace std;

bool Core::addTrain() {

	if(sizeC < 2) {
		cout << "Not enought points" << endl;
		return false;
	}

	Train tr;

	cout << "Enter info about this route:" << endl;

	while(true){
		int buf_;
		bool flag = true;
		cout << "Number of the route: ";
		cin << buf;
		cout << endl;
		for(int i = 0; i < sizeT; i++)
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
                cin << buf_;
		cout << endl;
                if(buf > 0) {
                        tr.set_speed(buf_);
                        break;
                }
                else {
                        cout << "The speed must be over than 0" << endl;
                }
        }

        while(true){
                string buf_;
                bool flag = true;
                cout << "Sending point: ";
                cin.getline(buf_,256,'\n');
		cout << endl;
                for(int i = 0; i < sizeC; i++)
                        if(buf_ == arrCity[i].get_city_name()){
                                flag = false;
                        }
                if(flag) {
                        tr.set_train_city_from(buf_);
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
		cin << buf_m;
		cout << endl;
                if((buf_m < 60) && (buf_m >= 0)) {
                        break;
                }
                else {
                        cout << "Incorrect input. Please try again" << endl;
                }
	}

	tr.set_train_time_otb(MtoT(buf_h * 60 + buf_m));

	tr = calcTime(tr);

        while(true) {
		int buf_;
                cout << "Numbers of cars kupe: ";
                cin >> buf_;
                cout << endl;
                if(buf_ > 0)) {
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
                if(buf_ > 0)) {
                        tr.set_train_vagoni_kupe(buf_);
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
                if(buf_ > 0)) {
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
                if(buf_ > 0)) {
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
                if(buf_ > 0)) {
                        tr.set_cost_kupe(buf_);
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
                if(buf_ > 0)) {
                        tr.set_cost_plackart(buf_);
                        break;
                }
                else {
                        cout << "Incorrect input. Please try again" << endl;
                }
        }

	ifstream f;
	f.open(fTrain);
	for(int i = 0; i < sizeT; i++) {
		f << arrTrain[i];
	}
	f << tr;
	return false;
}

bool Core::removeTrain() { //udalenie po nomeru marshruta, vizov cherez while(obj.removeTrain())
	if(sizeT == 0) {
		cout << "The list of directions is empty" << endl;
		return false;
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
		return false;
	}

	for(int i = 0; i < sizeP; i++) {
		if((arrPassenger[i].get_condition() < 2) && (arrPassenger[i].get_train_number())) {
			flag = false;
			break;
		}
	}
	if(!flag) {
		cout << "This route is used by passengers right now. Try do this later" << endl;
		return false;
	}

	ifstream f;
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
	return false;
}

bool Core::changeTrain() { //Change of direction by number of direction
	if(sizeT == 0) {
		cout << "The list of directions is empty" << endl;
		return false;
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
                return false;
        }

        for(int i = 0; i < sizeP; i++) {
                if((arrPassenger[i].get_condition() < 2) && (arrPassenger[i].get_train_number())) {
                        flag = false;
                        break;
                }
        }
        if(!flag) {
                cout << "This route is used by passengers right now. Try do this later" << endl;
                return false;
        }

	Train tr;

	cout << "Enter new info about this direction:" << endl;

	while(true){
		int buf_;
		bool flag = true;
		cout << "Number of the route: ";
		cin << buf;
		cout << endl;
		if(buf_ != buff){
			for(int i = 0; i < sizeT; i++)
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
                cin << buf_;
		cout << endl;
                if(buf > 0) {
                        tr.set_speed(buf_);
                        break;
                }
                else {
                        cout << "The speed must be over than 0" << endl;
                }
        }

        while(true){
                string buf_;
                bool flag = true;
                cout << "Sending point: ";
                cin.getline(buf_,256,'\n');
		cout << endl;
                for(int i = 0; i < sizeC; i++)
                        if(buf_ == arrCity[i].get_city_name()){
                                flag = false;
                        }
                if(flag) {
                        tr.set_train_city_from(buf_);
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
	while(true) {
		cout << "Departure Minute: ";
		cin << buf_m;
		cout << endl;
                if((buf_m < 60) && (buf_m >= 0)) {
                        break;
                }
                else {
                        cout << "Incorrect input. Please try again" << endl;
                }
	tr.set_train_time_otb(MtoT(buf_h * 60 + buf_m));

	tr = calcTime(tr);

        while(true) {
		int buf_;
                cout << "Numbers of cars kupe: ";
                cin >> buf_;
                cout << endl;
                if(buf_ > 0)) {
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
                if(buf_ > 0)) {
                        tr.set_train_vagoni_kupe(buf_);
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
                if(buf_ > 0)) {
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
                if(buf_ > 0)) {
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
                if(buf_ > 0)) {
                        tr.set_cost_kupe(buf_);
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
                if(buf_ > 0)) {
                        tr.set_cost_plackart(buf_);
                        break;
                }
                else {
                        cout << "Incorrect input. Please try again" << endl;
                }
        }

	ifstream f;
	f.open(fTrain);
	for(int i = 0; i < sizeT; i++) {
		if(arrTrain.get_train_number() == buff) {
			f << tr;
		}
		else {
			f << arrTrain[i];
		}
	}
	f.close(fTrain);

	f.open(fPassenger);
        for(int i = 0; i < sizeP; i++) {
                if(arrPassenger.get_train_number() != buff) {
                        f << arrPassenger[i];
                }
                else {
			cout << "This person will be removed from the list of passengers - ";
                        cout << "Name: " << arrPassenger[i].get_name();
			cout << ", Age: " << arrPassenger[i].get_age();
			cout << ", Sending time: " << arrPassenger[i].get_time_ot();
			if(arrPassenger[i].get_spot() == 0) {
                        	cout << ", Kupe";
			}
			else {
                        	cout << ", Plackart";
			}
                        cout << ", Car number: " << arrPassenger[i].get_n_vagona();
                        cout << ", Seat number: " << arrPassenger[i].get_n_mesta();
                        cout << ", From: " << arrPassenger[i].get_city_from();
                        cout << ", To: " << arrPassenger[i].get_city_to() << endl;
                }
        }
	f.close();

	return false;
}

void Core::outputTrain() {
	cout << "The list of the directions:" << endl;
	for(int i = 0; i < sizeT; i++) {
		cout << "Number of the direction: " << arrTrain[i].get_train_number();
                cout << ", Speed: " << arrTrain[i].get_train_speed();
                cout << ", From: " << arrTrain[i].get_train_city_from();
                cout << ", To: " << arrTrain[i].get_train_city_to();
                cout << ", Distance: " << arrTrain[i].get_distance();
                cout << ", Sending time: " << arrTrain[i].get_time_otb();
                cout << ", Arrival time: " << arrTrain[i].get_time_prib();
                cout << ", Travel time: " << arrTrain[i].get_time_puti();
                cout << ", Kupe capacity: " << arrTrain[i].get_capacity_kupe();
                cout << ", Plackart capacity: " << arrTrain[i].get_capacity_plackart();
                cout << ", Number of cars kupe: " << arrTrain[i].get_train_vagoni_kupe();
                cout << ", Number of cars plackart: " << arrTrain[i].get_train_vagoni_plackart();
                cout << ", Kupe cost: " << arrTrain[i].get_train_cost_kupe();
                cout << ", Plackart cost: " << arrTrain[i].get_train_cost_plackart() << endl;
	}
}

void Core::searchTrainNumber() {
	cout << "Enter the number of the direction: "
	int buf_;
	bool flag = false;
	cin >> buf_;
	cout << endl;
	for(int i = 0; i < sizeT; i++) {
		if(buf_ == arrTrain[i].get_train_number()) {
	                cout << "Number of the direction: " << arrTrain[i].get_train_number();
        	        cout << ", Speed: " << arrTrain[i].get_train_speed();
                	cout << ", From: " << arrTrain[i].get_train_city_from();
                	cout << ", To: " << arrTrain[i].get_train_city_to();
                	cout << ", Distance: " << arrTrain[i].get_distance();
                	cout << ", Sending time: " << arrTrain[i].get_time_otb();
                	cout << ", Arrival time: " << arrTrain[i].get_time_prib();
                	cout << ", Travel time: " << arrTrain[i].get_time_puti();
                	cout << ", Kupe capacity: " << arrTrain[i].get_capacity_kupe();
                	cout << ", Plackart capacity: " << arrTrain[i].get_capacity_plackart();
                	cout << ", Number of cars kupe: " << arrTrain[i].get_train_vagoni_kupe();
                	cout << ", Number of cars plackart: " << arrTrain[i].get_train_vagoni_plackart();
                	cout << ", Kupe cost: " << arrTrain[i].get_train_cost_kupe();
                	cout << ", Plackart cost: " << arrTrain[i].get_train_cost_plackart() << endl;
			flag = true;
			break;
		}
	}
	if(!flag) {
		cout << "The direction with this number doesn't exist" << endl;
	}
}

void Core::searchTrainPoint() {
        cout << "Enter the point from: "
        int bufFrom;
        cin.getline(bufFrom,256,'\n');
        cout << endl;
        cout << "Enter the point to: "
        int bufTo;
        cin.getline(bufTo,256,'\n');
        cout << endl;

        for(int i = 0; i < sizeT; i++) {
                if((bufFrom == arrTrain[i].get_train_city_from()) && (bufTo == arrTrain[i].get_train_city_to())) {
                        cout << "Number of the direction: " << arrTrain[i].get_train_number();
                        cout << ", Speed: " << arrTrain[i].get_train_speed();
                        cout << ", From: " << arrTrain[i].get_train_city_from();
                        cout << ", To: " << arrTrain[i].get_train_city_to();
                        cout << ", Distance: " << arrTrain[i].get_distance();
                        cout << ", Sending time: " << arrTrain[i].get_time_otb();
                        cout << ", Arrival time: " << arrTrain[i].get_time_prib();
                        cout << ", Travel time: " << arrTrain[i].get_time_puti();
                        cout << ", Kupe capacity: " << arrTrain[i].get_capacity_kupe();
                        cout << ", Plackart capacity: " << arrTrain[i].get_capacity_plackart();
                        cout << ", Number of cars kupe: " << arrTrain[i].get_train_vagoni_kupe();
                        cout << ", Number of cars plackart: " << arrTrain[i].get_train_vagoni_plackart();
                        cout << ", Kupe cost: " << arrTrain[i].get_train_cost_kupe();
                        cout << ", Plackart cost: " << arrTrain[i].get_train_cost_plackart() << endl;
                        flag = true;
                        break;
                }
        }
        if(!flag) {
                cout << "The direction with this points doesn't exist" << endl;
        }
}
