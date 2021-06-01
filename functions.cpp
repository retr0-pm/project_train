#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include "core.h"


using namespace std;

void Core::checkTime() {
	cout << "Global Time: " << gt.get_d() << gt.get_h() << gt.get_m() << endl;
}

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
	ofstream f;
	f.open(fTime);
	f << gt;
	f.close();

	f.open(fPassenger);
	for(int i = 0; i < sizeC; i++) {
		Time buf_time_ot;
		Time buf_time_prib;
		buf_time_prib = arrPassenger[i].get_time_prib();
		buf_time_ot = arrPassenger[i].get_time_ot();

		if(TtoM(buf_time_ot) > TtoM(gt)) {
			arrPassenger[i].set_condition(0);
		}
		else if(TtoM(buf_time_prib) >= TtoM(gt)) {
			arrPassenger[i].set_condition(2);
		}
		else {
			arrPassenger[i].set_condition(1);
		}
		f << arrPassenger[i];
	}
	f.close();
}

Train Core::calcTime(Train &t) {
	//calculation distance
	float x1,x2,y1,y2;
	for(int i = 0; i < sizeC; i++) {
		if (t.get_train_city_from() == arrCity[i].get_city_name()) {
			x1 = arrCity[i].get_city_x();
			y1 = arrCity[i].get_city_y();
		}

                if (t.get_train_city_to() == arrCity[i].get_city_name()) {
                        x2 = arrCity[i].get_city_x();
                        y2 = arrCity[i].get_city_y();
                }

	}
	float _distance;
	_distance = sqrt(pow((x1-x2),2) + pow((y1-y2),2));
	t.set_distance(_distance);

	//calculation t_puti
	int tm;
	Time _t_puti;
	Time _t_prib;
	tm = _distance / (t.get_train_speed() / 60);
	_t_puti = MtoT(tm);
	t.set_time_puti(_t_puti);

	//calculation t_prib
	_t_prib = t.get_time_otb() + _t_puti;
	_t_prib.set_d(0);
	_t_prib.set_h(_t_prib.get_h() % 24);
	t.set_time_prib(_t_prib);

	return t;
}
