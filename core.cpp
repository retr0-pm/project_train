void Core::sizeCity(){
	ofsteram f;
	f.open(fCity);
	size = 0;
	string buf;
	while(f.peek() != EOF){
		getline (f,buf);
		size++;
	}
	sizeC=size/3;
	f.close();	
} //Opredelenie razmera massiva gorodov
void Core::sizeTrain(){
	ofsteram f;
	f.open(fTrain);
	size = 0;
	string buf;
	while(f.peek() != EOF){
		getline (f,buf);
		size++;
	}
	sizeT=size/14;
	f.close();	
}  //Opredelenie razmera massiva reisov
void Core::sizePassenger(){
	ofsteram f;
	f.open(fPassenger);
	size = 0;
	string buf;
	while(f.peek() != EOF){
		getline (f,buf);
		size++;
	}
	sizeP=size/8;
	f.close();	
}  //Opredelenie razmera massiva passagirov

void fArrCity(){
	arrCity = new City[sizeC];
	ofstream f;
	f.open(fCity);
	for (int i = 0; i < sizeC; i++) {
		f >> arrCity[i];
	}
	f.close();
} //zanesenie iz faila v massiv gorodov
void fArrTrain(){
	arrTrain = new Train[sizeT];
	ofstream f;
	f.open(fTain);
	for (int i = 0; i < sizeT; i++) {
		f >> arrTrain[i];
	}
	f.close();
} //zanesenie iz faila v massiv reisov
void fArrPassenger(){
	ArrPassenger = new City[sizeP];
	ofstream f;
	f.open(fPassenger);
	for (int i = 0; i < sizeP; i++) {
		f >> ArrPassenger[i];
	}
	f.close();
} //zanesenie iz faila v massiv passagirov
void getGT{
	ofsteram f;
	f.open(fTime);
	f >> gt;
	f.close();
}; //zanesenie iz faila globalnogo vremeni
void clArrCity(){
	delete [] arrCity;
} //ochistka pamyati massiva gorodov
void clArrTrain{
	delete [] arrTrain;
}
//ochistka pamyati massiva reisov
void clArrPassenger(){
	delete [] arrPassenger;
} //ochistka pamyati massiva passagirov
