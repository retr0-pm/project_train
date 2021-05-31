class Core {
private:
char *fCity;  //Названия файла БД gorodov
char *fTrain;  //Названия файла БД reisov
char *fPassenger;  //Названия файла БД passagirov
char *fTime; // Nazvanie faila Globalnogo vremeni
City *arrCity; //Массив, связанный с БД городов
Train *arrTrain; //Массив, связанный с БД рейсов
Passenger *arrPassenger;  //Массив, связанный с БД пассажиров
int sizeT; // Кол-во объектов типа Train
int sizeC; // Кол-во объектов типа City
int sizeP; // Кол-во объектов типа Passenger
Time gt; //Global Time - globalnoe vremya
public:

Core (char *_fCity, char *_fTrain, char *_fPassenger, char *_fTime);

bool isitokay();

void sizeCity(); //Opredelenie razmera massiva gorodov
void sizeTrain(); //Opredelenie razmera massiva reisov
void sizePassenger(); //Opredelenie razmera massiva passagirov

void fArrCity(); //zanesenie iz faila v massiv gorodov
void fArrTrain(); //zanesenie iz faila v massiv reisov
void fArrPassenger(); //zanesenie iz faila v massiv passagirov
void getGT; //zanesenie iz faila globalnogo vremeni

void clArrCity(); //ochistka pamyati massiva gorodov
void clArrTrain(); //ochistka pamyati massiva reisov
void clArrPassenger(); //ochistka pamyati massiva passagirov

//Train
void addTrain(); //Dobavit'
void removeTrain(); //Udalit'
void changeTrain(); // Izmenit'
void outputTrain(); // Vivesti polniy spisok
void searchTrainNumber(); // Poisk reisa po nomeru
void searchTrainPoint(); // Poisk reias po gorodam

void calcTime(); // Calulation distance, t_puti, t_prib

//Passenger
void addPassenger();
void removePassenger();
void changePassenger();
void outputPassenger();
void searchPassenger();

bool calcNumber(); // Vichislenie nomera reisa po dvum gorodam
void calcPosition(); // Vishislenie tekushey koordinati
void calcMesta(); // Vichislenie nomera vagona i mesta v nem

//City
void addCity();
void removeCity();
void changeCity();
void outputCity();
void searchCity();

//Time
void checkTime(); // Vivod tekushego vremeni
void rewindTime(); // Smehenie tekushego vremeni

};
