#include <iostream>
#include <fstream>
#include <string>
#include "menu.h"

using namespace std;

Menu::Menu() {
/*        system("clear");
        system("sl -F");
        system("clear");
        system("figlet -ctk -f slant Welcome to the PROJECT TRAIN"); */
}

Menu::~Menu() {
       /* system("clear");
        system("sl -l");
        system("clear");
        system("figlet -ctk -f slant Come again :)");*/
}

void Menu::Start(Core &obj) {
	bool fl = false;
	int sw = 0;
	while(true){
		int swp = -1;
		switch(sw) {
		case 0:
			cout << "Добро пожаловать." << endl;
			cout << "Выберите действие:" << endl;
			cout << "0. Посмотреть инструкцию еще раз" << endl;
			cout << "1. Работа с базой данных городов" << endl;
			cout << "2. Работа с базой данных рейсов" << endl;
			cout << "3. Работа с базой данных пассажиров" << endl;
			cout << "4. Время" << endl;
			cout << "5. Выход" << endl;
			break;
		case 1:
			cout << "Выберите действие:" << endl;
			cout << "1. Добавть город" << endl;
                        cout << "2. Удалить город" << endl;
                        cout << "3. Редактировать город" << endl;
                        cout << "4. Вывести базу данных городов" << endl;
                        cout << "5. Поиск городапо названию" << endl;
                        cout << "0. назад" << endl;
                        cout << "Ваш выбор: ";
			cin >> swp;
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
					obj.outputCity();
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
			cout << "Выберите действие::" << endl;
			cout << "1. Добавить рейс" << endl;
                        cout << "2. Удалить рейс" << endl;
                        cout << "3. Редактировать рейс" << endl;
                        cout << "4. Вывести базу данных рейсов" << endl;
                        cout << "5. Поиск рейса по номеру" << endl;
			cout << "6. Поиск рейса по городам" << endl;
                        cout << "0. Назад" << endl;
                        cout << "Ваш выбор: ";
			cin >> swp;
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
					obj.addTrain();
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
					obj.removeTrain();
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
					obj.changeTrain();
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
					obj.outputTrain();
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
					obj.searchTrainNumber();
                                        obj.clArrCity();
                                        obj.clArrTrain();
                                        obj.clArrPassenger();

					break;
                                case 6:
                                        obj.sizeCity();
                                        obj.sizeTrain();
                                        obj.sizePassenger();
                                        obj.fArrCity();
                                        obj.fArrTrain();
                                        obj.fArrPassenger();
                                        obj.getGT();
                                        obj.searchTrainPoint();
                                        obj.clArrCity();
                                        obj.clArrTrain();
                                        obj.clArrPassenger();

                                        break;

				default:
					break;
			}
			break;
		case 3:
                        cout << "Выберите действие:" << endl;
                        cout << "1. Добавить пассажира" << endl;
                        cout << "2. Удалить пассажира" << endl;
                        cout << "3. Вывести базу данных пассажиров" << endl;
                        cout << "4. Найти пассажира" << endl;
                        cout << "0. Назад" << endl;
                        cout << "Ваш выбор: ";
                        cin >> swp;
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
					obj.addPassenger();
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
					obj.removePassenger();
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
					obj.outputPassenger();
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
					obj.searchPassenger();
                                        obj.clArrCity();
                                        obj.clArrTrain();
                                        obj.clArrPassenger();

					break;
				default:
					break;
			}
			break;
		case 4:
			cout << "Выберите действие:" << endl;
			cout << "1. Посмотреть текущее время" << endl;
                        cout << "2. Перемотка времени" << endl;
                        cout << "0. Назад" << endl;
			cout << "Ваш выбор: ";
			cin >> swp;
			cout << endl;
			switch(swp) {
				case 0:
					break;
				case 1:
					obj.getGT();
					obj.checkTime();
					break;
				case 2:
					obj.sizePassenger();
					obj.fArrPassenger();
					obj.getGT();
					obj.rewindTime();
					obj.getGT();
					obj.checkTime();
					obj.clArrPassenger();
				default:
					break;
			}
			break;
		case 5:
			fl = true;
			break;
		default:
			cout << "Такого действия не существует. Введите 0 чтобы посмотреть инструкцию" << endl;
			break;
		}

                if(fl) {
                        break;
                }

		cout << "Выберите действие (инструкция - 0): ";
		cin >> sw;
		cout << endl;
	}
}
