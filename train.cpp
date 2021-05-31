#include <iostream>
#include <string>
#include <fstream>
#include "classes.h"

using namespace std;

void Train::outTrain() {
cout << "Number of the direction: " << number;
cout << ", Speed: " << speed;
cout << ", From: " << from;
cout << ", To: " << to;
cout << ", Distance: " << distance;
cout << ", Sending time: " << t_otb;
cout << ", Arrival time: " << t_prib;
cout << ", Travel time: " << t_puti;
cout << ", Kupe capacity: " << capacity_kupe;
cout << ", Plackart capacity: " << capacity_plackart;
cout << ", Number of cars kupe: " << vagoni_kupe;
cout << ", Number of cars plackart: " << vagoni_plackart;
cout << ", Kupe cost: " << cost_kupe;
cout << ", Plackart cost: " << cost_plackart << endl;
}
