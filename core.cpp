void Core::calcPosition(Passanger t){
	Train buf;
	for(i=0, i<sizeT, i++){
		if(arrTrain[i].train_number == t.train_number;){
			buf = arrTrain[i];
		}
	}
	City buf1, buf2;
	for(i=0, i<sizeC, i++){
		if(arrCity[i].city_name == buf.from;){
			buf1 = arrCity[i];
		}
	}
	for(i=0, i<sizeC, i++){
		if(arrCity[i].city_name == buf.to;){
			buf2 = arrCity[i];
		}
	}
	Time t_in_d=gt-t.time_ot;
	int minuts1=gt.TtoM;
	int minuts2=t_in_d.TtoM;
	float m=((minuts1-munuts2)*sqrt((buf2.x-buf1.x)*(buf2.x-buf1.x)+(buf2.y-buf1.y)*(buf2.y-buf1.y)))/buf.speed;//koeff. for formula
	float Xx=(buf1.x+m*buf2.x)/(1+m);//final x of time's moment
	float Yy=(buf1.y+m*buf2.y)/(1+m);//final y of time's moment
}
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
