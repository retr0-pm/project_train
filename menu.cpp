#include <iostream>

using namespace std;

Menu::Menu() {
        system("clear");
        system("sl -F");
        system("clear");
        system("figlet -ctk -f slant Welcome to the PROJECT TRAIN");
}

Menu::~Menu() {
        system("clear");
        system("sl -l");
        system("clear");
        system("figlet -ctk -f slant Come again :)");
}

void Menu::Start(Core &obj) {
	bool fl = false;
	int sw = 0;
	while(true){
		int swp = -1;
		switch(sw) {
		case 0:
			cout << "Eto Project Train" << endl;
			cout << "Viberite svoe deystvie:" << endl;
			cout << "0. Prosmotret instruciyu escho raz" << endl;
			cout << "1. Rabota s BD punktami" << endl;
			cout << "2. Rabota s BD reisov" << endl;
			cout << "3. Rabota s BD passagirov" << endl;
			cout << "4. Vremya" << endl;
			cout << "5. Vihod" << endl;
			break;
		case 1:
			cout << "Viberite deystvie iz predlozhennih:" << endl;
			cout << "1. Dobavit punkt" << endl;
                        cout << "2. Udalit punkt" << endl;
                        cout << "3. Redaktirovat punkt" << endl;
                        cout << "4. prosmotret vse" << endl;
                        cout << "5. Nayti po nazaniyu" << endl;
                        cout << "0. nazad" << endl;
                        cout << "Vash vibor: ";
			cin << swp;
			cout << endl;
			switch(swp) {
				case 0:
					break;
				case 1:
					obj.sizeCity();
                                        obj.sizeTrain();
                                        obj.sizePassenger();
					obj.fArrCity();
                                        obj.fArrTrain();
                                        obj.fArrPassenger();
					obj.getGT();
					obj.addCity();
					obj.clArrCity();
                                        obj.clArrTrain();
                                        obj.clArrPassenger();

					break;
				case 2:
	                                obj.sizeCity();
                                        obj.sizeTrain();
                                        obj.sizePassenger();
                                        obj.fArrCity();
                                        obj.fArrTrain();
                                        obj.fArrPassenger();
                                        obj.getGT();
					obj.removeCity();
                                        obj.clArrCity();
                                        obj.clArrTrain();
                                        obj.clArrPassenger();

					break;
				case 3:
                                        obj.sizeCity();
                                        obj.sizeTrain();
                                        obj.sizePassenger();
                                        obj.fArrCity();
                                        obj.fArrTrain();
                                        obj.fArrPassenger();
                                        obj.getGT();
					obj.changeCity();
                                        obj.clArrCity();
                                        obj.clArrTrain();
                                        obj.clArrPassenger();

					break;
				case 4:
                                        obj.sizeCity();
                                        obj.sizeTrain();
                                        obj.sizePassenger();
                                        obj.fArrCity();
                                        obj.fArrTrain();
                                        obj.fArrPassenger();
                                        obj.getGT();
					obj.ouputCity();
                                        obj.clArrCity();
                                        obj.clArrTrain();
                                        obj.clArrPassenger();

					break;
				case 5:
                                        obj.sizeCity();
                                        obj.sizeTrain();
                                        obj.sizePassenger();
                                        obj.fArrCity();
                                        obj.fArrTrain();
                                        obj.fArrPassenger();
                                        obj.getGT();
					obj.searchCity();
                                        obj.clArrCity();
                                        obj.clArrTrain();
                                        obj.clArrPassenger();

					break;
				default:
					break;
			}

			break;
		case 2:
			
			break;
		case 3:
			
			break;
		case 4:
			
			break;
		case 5:
			fl = true;
			break;
		default:
			cout << "Takogo deystviya ne sushestvuet. Vvedite 0 chtobi posmotret insrukciyu" << endl;
			break;
		}

                if(fl) {
                        break;
                }

		cout << "Pojaluysta, viberite deystvie (instucia - 0): ";
		cin >> sw;
		cout << endl;
	}
