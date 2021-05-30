#include <iostream>
#include <cmath>
#include <string>
#include <fstream>


using namespace std;

void Core::rewindTime() {
	int _d, _h, _m;
	Time shift;
	cout << "Please enter time that you want to rewind:" << endl;

	cout << "Days: ";
	cin >> _d;
	cout << endl;
	shift.set_d(_d);

	while(true) {
		cout << "Hours: ";
		cin >> _h;
		if ((_h < 24) && (_h >= 0)) {
			shift.set_h(_h);
			break;
			cout << endl;
		}
		else {
			cout << "Incorrect value, please try again";
		}
	}

        while(true) {
                cout << "Minutes: ";
                cin >> _m;
                if ((_m < 60) && (_m >= 0)) {
                        shift.set_m(_m);
                        break;
                        cout << endl;
                }
                else {
                        cout << "Incorrect value, please try again" << endl;
                }
        }


	gt = gt + shift;
	ifstream f;
	f.open(fTime);
	f << gt;
	f.close();
}

Train Core::calcTime(Train t) {
	//calculation distance
	float x1,x2,y1,y2;
	for(int i = 0; i < sizeC; i++) {
		if (_city_from == arrCity[i].get_name()) {
			x1 = arrCity[i].get_city_x();
			y1 = arrCity[i].get_city_y();
		}

                if (_city_to == arrCity[i].get_name()) {
                        x2 = arrCity[i].get_city_x();
                        y2 = arrCity[i].get_city_y();
                }

	}
	_distance = sqrt(pow((x1-x2),2) + pow((y1-y2),2));

	//calculation t_puti
	int tm;
	tm = _distance / (_speed / 60);
	_t_puti = MtoT(tm);

	//calculation t_prib
	_t_prib = _t_otb + _t_puti;
	_t_prib.d = 0;
}

//Train
void Core::addTrain() {
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
		f << arrTrain[i];
	}
	f << tr;
}

bool Core::removeTrain() { //udalenie po nomeru marshruta, vizov cherez while(obj.removeTrain())
	int buf_;
	bool flag = false;
	cout << "Enter the number of the direction: ";
	cin >> buf_;
	cout << endl;
	for(int i = 0; i < sizeT; i++) {
		if(arrTrain[i].get_train_number == buf_) {
			
		}
	}
}































