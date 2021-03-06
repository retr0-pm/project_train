#include <fstream>
#include <string>
#include <iostream>
#include "time.h"
#include "passenger.h"
#include "train.h"
#include "city.h"

using namespace std;

/**
	\brief Основной класс.
	Класс работающий с массивами объектов других классов.
*/
class Core {
private:
char *fCity; 
char *fTrain;
char *fPassenger; 
char *fTime;
City *arrCity;
Train *arrTrain;
Passenger *arrPassenger;
int sizeT;
int sizeC;
int sizeP;
Time gt;
public:
/**
	\brief  Конструктор класса Core.
*/
Core (char *_fCity, char *_fTrain, char *_fPassenger, char *_fTime);
/**
	\brief Проверяет открылсь ли файлы.
	\return булевое значение для проверки успешности выполнения.
	Проверяет открылись ли файлы, проверяет является ли файл содержащий время пустым, если да то вписывает туда  строчку "0 0 0".
*/
bool isitokay();

/**
	\brief Определяет размер массива пунктов. 
*/
void sizeCity();
/**
	\brief Определяет размер массива рейсов. 
*/
void sizeTrain();
/**
	\brief Определяет размер массива пассажиров. 
*/
void sizePassenger(); 

/**
	\brief Занесение БД пунктов из файла в массив пунктов.
*/
void fArrCity();
/**
	\brief Занесение БД рейсов из файла в массив рейсов.
*/
void fArrTrain(); 
/**
	\brief Занесение БД пассажиров из файла в массив пассажиров.
*/
void fArrPassenger(); 
/**
	\brief Заносит из файла в переменную глобальное временя.
*/
void getGT(); 

/**
	\brief Отчистка массива городов.
*/
void clArrCity();
/**
	\brief Отчистка массива рейсов.
*/
void clArrTrain();
/**
	\brief Отчистка массива пассажиров.
*/
void clArrPassenger();


void addTrain();
void removeTrain();
void changeTrain();
void outputTrain();
void searchTrainNumber();
void searchTrainPoint();

/**
	\brief Заполнает поля обекта класcа Train.
	\param t рейс
	Заполняет поля которые дожны вычислятся автоматически.
*/
Train calcTime(Train &t);


void addPassenger();
void removePassenger();
void changePassenger();
void outputPassenger();
void searchPassenger();

/**
	\brief  Определяет номер рейса по 2-м городам.
	\param b Пассажир
	\return 0 или 1 - для проверки успешности выполнения. 
	Определяет номер рейса по городам записанным в обекте класса пасажир. 
*/
int calcNumber(Passenger &b);
/**
	\brief Вычисляет текущую координату.
	\param t Пассажир 
*/
void calcPosition(Passenger &t);
/**
	\brief Вычисляет номер вагона в составе и номер места в вагоне. 
	\param t Пассажир
	\return 0 или 1 - для проверки успешности выполнения.
*/
int calcMesta(Passenger &t);


void addCity();
void removeCity();
void changeCity();
void outputCity();
void searchCity();


void checkTime();
void rewindTime();
/**
	\brief переводит время из формата Time в минуты.
	\param t время
	\return возвращает чило равное количесто минут
*/
int TtoM(Time t);
/**
	\brief переводит время из минут в формат Time.
	\param t минуты
	\return возвращает время в формате день час минута, равное минутам
*/
Time MtoT(int t);
};
