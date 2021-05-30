void Core::calcMesto(Passenger t){
	int kol=0;
	
	Train buf;
	for(i=0, i<sizeT, i++){
		if(arrTrain[i].get_train_number() == t.train_number;){
			buf = arrTrain[i];
			break;
		}
	}
	for(i=0, i<sizeP, i++){
		if(buf.number == arrPassenger[i].get_train_number && buf.spot == arrPassenger[i].get_spot && arrPassenger[i].get_condition()==0){
			kol++;
		}
	}
	if(t.spot == 1){
		if(kol>=buf.capacity_plackart*buf.vagoni_plackart){
			cin<<"в плацкарте мест нет";
			return;
		}else{
			t.n_vagona=kol/capacity_plackart+1;
			t.n_mesta=kol/vagoni_plackart+1;
		}
	}
	if(t.spot == 0){
		if(kol>=buf.capacity_kupe*buf.vagoni_kupe){
			cin<<"в купе мест нет";
			return;
		}else{
			t.n_vagona=kol/capacity_kupe+1;
			t.n_mesta=kol/vagoni_kupe+1;
		}
	}
}

void Core::calcPosition(Passanger t){
	Train buf;
	for(i=0, i<sizeT, i++){
		if(arrTrain[i].get_train_number() == t.train_number;){
			buf = arrTrain[i];
			break;
		}
	}
	City buf1, buf2;
	for(i=0, i<sizeC, i++){
		if(arrCity[i].get_city_name() == buf.from;){
			buf1 = arrCity[i];
			break;
		}
	}
	for(i=0, i<sizeC, i++){
		if(arrCity[i].get_city_name() == buf.to;){
			buf2 = arrCity[i];
			break;
		}
	}
	Time t_in_d=gt-t.time_ot;
	int minuts1=gt.TtoM;
	int minuts2=t_in_d.TtoM;
	float m=((minuts1-munuts2)*sqrt((buf2.x-buf1.x)*(buf2.x-buf1.x)+(buf2.y-buf1.y)*(buf2.y-buf1.y)))/buf.speed;//koeff. for formula
	float Xx=(buf1.x+m*buf2.x)/(1+m);//final x of time's moment
	float Yy=(buf1.y+m*buf2.y)/(1+m);//final y of time's moment
	cout <<"Координата по х, на данный момент:"<< Xx;
	cout <<"Координата по у, на данный момент:"<< Yy;
}
void Core::calcPosition(Passanger t){
	Train buf;
	for(i=0, i<sizeT, i++){
		if(arrTrain[i].get_train_number() == t.train_number;){
			buf = arrTrain[i];
			break;
		}
	}
	City buf1, buf2;
	for(i=0, i<sizeC, i++){
		if(arrCity[i].get_city_name() == buf.from;){
			buf1 = arrCity[i];
			break;
		}
	}
	for(i=0, i<sizeC, i++){
		if(arrCity[i].get_city_name() == buf.to;){
			buf2 = arrCity[i];
			break;
		}
	}
	Time t_in_d=gt-t.time_ot;
	int minuts1=gt.TtoM;
	int minuts2=t_in_d.TtoM;
	float m=((minuts1-munuts2)*sqrt((buf2.x-buf1.x)*(buf2.x-buf1.x)+(buf2.y-buf1.y)*(buf2.y-buf1.y)))/buf.speed;//koeff. for formula
	float Xx=(buf1.x+m*buf2.x)/(1+m);//final x of time's moment
	float Yy=(buf1.y+m*buf2.y)/(1+m);//final y of time's moment
	cout <<"Координата по х, на данный момент:"<< Xx;
	cout <<"Координата по у, на данный момент:"<< Yy;
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

void Core::fArrCity(){
	arrCity = new City[sizeC];
	ofstream f;
	f.open(fCity);
	for (int i = 0; i < sizeC; i++) {
		f >> arrCity[i];
	}
	f.close();
} //zanesenie iz faila v massiv gorodov
void Core::fArrTrain(){
	arrTrain = new Train[sizeT];
	ofstream f;
	f.open(fTain);
	for (int i = 0; i < sizeT; i++) {
		f >> arrTrain[i];
	}
	f.close();
} //zanesenie iz faila v massiv reisov
void Core::fArrPassenger(){
	ArrPassenger = new City[sizeP];
	ofstream f;
	f.open(fPassenger);
	for (int i = 0; i < sizeP; i++) {
		f >> ArrPassenger[i];
	}
	f.close();
} //zanesenie iz faila v massiv passagirov
void Core::getGT{
	ofsteram f;
	f.open(fTime);
	f >> gt;
	f.close();
}; //zanesenie iz faila globalnogo vremeni
void Core::clArrCity(){
	delete [] arrCity;
} //ochistka pamyati massiva gorodov
void Core::clArrTrain{
	delete [] arrTrain;
}
//ochistka pamyati massiva reisov
void Core::clArrPassenger(){
	delete [] arrPassenger;
} //ochistka pamyati massiva passagirov
