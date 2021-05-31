#include <iostream>
#include <fstream>
#include <string>
#include "core.h"

using namespace std;

void Core::addPassenger() {
	if(sizeT < 1) {
		cout << "Net marshrutov" << endl;
		break;
	}

	Passenger bufP;

	string bufname;
	cout << "Enter the passenger name: ";
	getline(cin, bufname);
	bufP.set_name(bufname);

	while(true) {
		int bufage;
		cout << "Enter age: ";
		cin >> bufage;
		cout << endl;
		if(bufage >= 0) {
			bufP.set_age(bufage);
			break;
		}
		else {
			cout << "Age must be 0 or over 0" << endl;
		}
	}

	string bufA;
	string bufB;
	while(true) {
		cout << "From: ";
		getline(cin, bufA);
		cout << endl;
		cout << "To: ";
		getline(cin, bufB);
		cout << endl;
		bool prov = false;
		for(int i = 0; i < sizeT; i++) {
			if((arrTrain[i].get_train_city_from() == bufA) && (arrTrain[i].get_train_city_to() == bufB)) {
				prov = true;
				bufP.set_city_from(bufA);
				bufP.set_city_to(bufB);
				bufP.set_train_number(arrTrain[i].get_train_number());
				bufP.set_time_ot(MtoT((gt.get_d()+1) * 1440 + TtoM(arrTrain[i].get_time_otb())));
				bufP.set_time_prib(bufP.get_time_ot() + arrTrain[i].get_time_puti());
				bufP.set_condition(0);
				break;
			}
		}
		if(prov) {
			break;
		}
		else {
			cout << "This route doesn't exist" << endl;
		}
	}

	while(true) {
		int bufspot;
		cout << "Enter the spot, 0 - kupe, 1 - plackart: ";
		cin >> bufspot;
		if((bufspot == 0) || (bufspot == 1)) {
			bufP.set_spot(bufspot);
			break;
		}
	}

	int buf_n_k = 0;
	int buf_n_p = 0;
	int buf_v_k = 0;
	int buf_v_p = 0;
	for(int i = 0; i < sizeTrain; i++) {
		if(arrTrain[i].get_train_number() == bufP.get_train_number()) {
			buf_v_k = arrTrain[i].get_capacity_kupe();
			buf_n_k = arrTraint[i].get_train_vagoni_kupe();
			buf_v_p = arrTrain[i].get_capacity_plackart();
			buf_n_p = arrTrain[i].get_train_vagoni_plackart();
			break;
			}
		}
	}

	int sch = 0;
	for(int i = 0; i < sizeP; i++) {
		if((arrPassenger[i].get_train_number() == bufP.get_train_number()) && (arrPassenger[i].get_condition() == 0) && (arrPassenger[i].get_spot() == bufP.get_spot())) {
			sch++;
		}
	}

	if(bufP.get_spot() == 0) {
		if(sch < (buf_v_k * buf_n_k)) {
			bufP.set_n_mesta(sch%buf_v_k + 1);
			bufP.set_n_vagona(sch/buf_v_k + 1);
		}
		else {
			cout << "Nedostatochno mest" << endl;
			return;
		}
	}
	else {
		if(sch < (buf_v_p * buf_n_p)) {
                        bufP.set_n_mesta(sch%buf_v_p + 1);
                        bufP.set_n_vagona(sch/buf_v_p + buf_n_k + 1);
		}
		else {
			cout << "Nedostatochno mest" << endl;
			return;
		}
	}

	ifstream f;
	fopen(fPassenger);
	for(int i = 0; i < sizeP; i++) {
		f << arrTrain[i];
	}
	f << bufP;
	f.close();
}

void Core::removePassenger() {
	if(sizeP < 1) {
		cout << "Nekogo udalat" << endl;
		return;
	}

	string bufname;
	while(True) {
		cout << "Imya kogo udalit:";
		getline(cin,bufname);
		cout << endl;
		bool proverka = true;

		for(int i = 0; i < sizeP; i++) {
			if(arrPassenger[i].get_name() == bufname) {
				proverka = false;
				break;
			}
		}

		if(proverka) {
			cout << "Net takogo cheloveka. Poprobuyte esche raz" << endl;
		}
	}

	ifstream f;
	fopen(fPassenger);
	for(int i = 0; i < sizeP; i++) {
		if(arrPassenger[i].get_name() != bufname;) {
			f << arrPassenger[i];
		}
	}
	f.close();
}

void Core::outputPassenger() {
	if(sizeP < 1) {
		cout << "Pusto" << endl;
		return;
	}

	for(int i = 0; i < sizeP; ) {
		arrPassenger[i].outPassenger();
	}
}

void Core::searchPassengerName() {
        if(sizeP < 1) {
                cout << "Pusto" << endl;
                return;
	}

}

void Core::searchPassengerTrain() {
        if(sizeP < 1) {
                cout << "Pusto" << endl;
                return;
        }

}






































