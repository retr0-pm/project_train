#include <iostream>
#include "passenger.h"

using namespace std;

void Passenger::outPassenger() {
	cout << "Name: " << name;
	cout << ", Age: " << age;
	cout << ", The number of the direction: " << train_number;
	cout << ", Sending time: " << time_ot;
	if(spot == 0) {
                 	cout << ", Kupe";
	}
	else {
                    	cout << ", Plackart";
	}
	cout << ", Car number: " << n_vagona;
	cout << ", Seat number: " << n_mesta;
	cout << ", From: " << city_from;
	cout << ", To: " << city_to;
	cout << ", Condition: ";
	switch(condition) {
		case 0:
			cout << "Waiting" << endl;
			break;
		case 1:
			cout << "On the way" << endl;
			break;
		case 2:
			cout << "Arrived" << endl;
			break;
	}
}
