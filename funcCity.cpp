#include <iostream>
#include <fstream>
#include <string>
#include "core.h"

using namespace std;

void Core::addCity() {
	City bufC;

	while(true){
		cout << "Enter the name of the point: ";
		string buf_;
		bool flag_ = true;
		cin.getline(buf_, 256, '\n');
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
			cout << "The point with this name already exist. Please try any other name" << endl;
		}
	}

	float a,b;
	cout << "Enter coordinates in format (x:y): (";
	cin >> "(" >> a >> ":" >> b >> ")";
	cout << endl;
	bufC.set_coordinates(a,b);

	ifsteam f;
	f.open(fCity);
	for (int i = 0; i < sizeC; i++) {
		f << arrCity[i];
	}
	f << bufC;
	f.close();

}

void Core::removeCity() {
	if(sizeC < 1) {
		cout << "There are no one point" << endl;
		return;
	}

	string buf_;
	cout << "Enter the name of the point:";
	cin.getline(buf_, 256, '\n');
	cout << endl;

	bool flag_ = false;
	for (int i = 0; i < sizeC; i++) {
		if(buf_ == arrCity[i].get_city_name())
			flag_ = true;
			break;
		}
	}
	if(!flag_) {
		cout << "This point doesn't exist" << endl;
		return;
	}

	for(int i = 0; i < sizeP; i++) {
		if((arrPassenger[i].get_condition() < 2) && ((arrPassenger[i].get_city_from() == buf_) || (arrPassenger[i].get_city_to() == buf_))) {
			flag_ = false;
			break;
		}
	}
	if(!flag_) {
		cout << "This point is used by passneger right now. Try do this later" << endl;
		return;
	}

	ifstream f;
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
			cout << "This direction also will be removed - ";
			arrTrain[i].outTrain;
		}
	}
	f.close();

	for (int i = 0; i < sizeP; i++) {
                if((arrPassenger[i].get_city_from() != buf_) && (arrPassenger[i].get_city_to() != buf_)) {
                        f << arrTrain[i];
                }
                else {
			cout << "This person also will be removed from the list of passengers - ";
			arrPassenger[i].outPassenger();
		}
	}
	f.close();

	return;
}

void Core::changeCity() {
        if(sizeC < 1) {
                cout << "There are no one point" << endl;
                return;
        }

        string buf_;
        cout << "Enter the name of the point:";
        cin.getline(buf_, 256, '\n');
        cout << endl;

        bool flag_ = false;
        for (int i = 0; i < sizeC; i++) {
                if(buf_ == arrCity[i].get_city_name())
                        flag_ = true;
                        break;
                }
        }
        if(!flag_) {
                cout << "This point doesn't exist" << endl;
                return;
        }

        for(int i = 0; i < sizeP; i++) {
                if((arrPassenger[i].get_condition() < 2) && ((arrPassenger[i].get_city_from() == buf_) || (arrPassenger[i].get_city_to() == buf_))) {
                        flag_ = false;
                        break;
                }
        }
        if(!flag_) {
                cout << "This point is used by passneger right now. Try do this later" << endl;
                return;
        }

        City bufC;
        while(true){
                cout << "Enter the new name of the point: ";
                string buff;
                cin.getline(buff, 256, '\n');
		if(buff != buf_) {
                	for(int i = 0; i < sizeC; i++) {
                        	if(arrCity[i].get_city_name() == buff) {
                                	flag_ = false;
                                	break;
                        	}
                	}
		}
                if(flag_) {
                        bufC.set_city_name(buf_);
                        break;
                }
                else {
                        cout << "The point with this name already exist. Please try any other name" << endl;
                }
        }

        float a,b;
        cout << "Enter coordinates in format (x:y): (";
        cin >> "(" >> a >> ":" >> b >> ")";
        cout << endl;
        bufC.set_coordinates(a,b);

	ifstream f;
	f.open(fCity);
	for(int i = 0; i < sizeC; i++) {
		if(arrCity[i].get_city_name() == buf) {
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
                        cout << "This direction also will be removed - ";
                        arrTrain[i].outTrain;
                }
        }
        f.close();

        for (int i = 0; i < sizeP; i++) {
                if((arrPassenger[i].get_city_from() != buf_) && (arrPassenger[i].get_city_to() != buf_)) {
                        f << arrTrain[i];
                }
                else {
                        cout << "This person also will be removed from the list of passengers - ";
                        arrPassenger[i].outPassenger();
                }
        }
        f.close();

        return;
}

void Core::outputCity() {
	if(sizeC < 1) {
		cout << "The list of points is empty" << endl;
		return;
	}

	cout << "The list of points: " << endl;
	for(int i = 0; i < sizeC; i++) {
		arrCity[i].outCity();
	}

	return;
}

void Core::searchCity() {
	if(sizeC < 1) {
		cout << "The list of points is empty" << endl;
		return;
	}

	cout << "Enter the name of the point:";
	string buf_;
	bool flag_ = false;
	cin.getline(buf_, 256, '\n');
	cout << endl;
	for(int i = 0; i < sizeC; i++) {
		if(arrCity[i].get_city_name == buf) {
			arrCity[i].outCity();
			flag_ = true;
			break;
		}
	}
	if(!flag_) {
		cout << "The point with this name doesn't exist" << endl;
	}

	return;
}

























