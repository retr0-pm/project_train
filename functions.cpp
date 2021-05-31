#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include "core.h"


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
