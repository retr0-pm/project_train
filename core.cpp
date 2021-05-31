void Core::searchPassenger(){
	if(sizeP == 0){cout<<"База данных о пассажирах пуста"<<endl; return;}
	int a;
	cout<<"1 - поиск по имени. 2 - поиск по номеру рейса";
	cin>>a;
	switch(a):
		case(1):	
			string buf1_;
			cout<<"введие имя:";
			cin>>buf1_;
			int s = 0;
			for(int i = 0; i < sizeP; i++) {
				if(arrPassenger.get_name() == buf1_){
					arrPassenger[i].outPassenger();
					if(arrPassenger[i].get_condition == 1){
						calcPosition(arrPassenger[i]);
					}
					s++;
					break;
				}
			}if(s == 0){cout<<"ничего не найдени";}
		break;
		case(2):
			string buf1_;
			cout<<"введие номер:";
			cin>>buf1_;
			int s = 0;
			for(int i = 0; i < sizeP; i++) {
				if(arrPassenger[i].get_train_number() == buf1_){
					arrPassenger[i].outPassenger();
				}
				if(arrPassenger[i].get_condition == 1){
					calcPosition(arrPassenger[i]);
				}
			}if (s == 0 ){cout<<"ничего не найдени";}
		break;
		case(3):{
			return;
		}	 
}
void Core::outputPassenger(){
	for(int i = 0; i < sizeP; i++) {
		if(arrPassenger.get_name() != buf1_){
			arrPassenger[i].outPassenger();
			if(arrPassenger[i].get_condition == 1){
				calcPosition(arrPassenger[i]);
			}
		}
	}
}
void Core::removePassenger(){
	if(sizeP == 0){cout<<"База данных о пассажирах пуста"<<endl;}
	string buf1_;
	cout<<"введие имя:";
	cin>>buf1_;
	ifstream f;
	f.open(fPassenger);
	for(int i = 0; i < sizeP; i++) {
		if(arrPassenger.get_name() != buf1_){
			f << arrPassenger[i];
		} else if(arrPassenger[i].get_conditions == 1) {
			cout<<"вы успешно убили человека"<<endl;
		}
	}
	f.close();
	return;
}

void Core::addPassenger(){
	if(sizeT < 1){
		cout<<"Нет ни одного маршрута"<<endl;
		return;
	}
	
	Passenger pas;
	while(1){
		string buf_;
		cout<<"введите имя:";
		cin>>buf_;
		cout<<endl;
		if(buf_ != " "){
			pas.set_name(buf_);
			break;
		}else
			cout<<"переданно неверное значение"<<endl;
	}
	while(1){
		int buf_
		cout<<"введите возраст:";
		cin>>buf_;
		cout<<endl;
		if(buf_ > 0){
			pas.set_age(buf_);
			break;
		}else
			cout<<"переданно неверное значение"<<endl;
	}
	while(1){
		while(1){
			int flag1, flag2;
				
			string buf1_;
			cout<<"введите город отбытия:";
			cin>>buf1_;
			cout<<endl;
				
			if(buf1_ == " "){
				pas.set_city_from(buf1_);
			}else{cout<<"переданно неверное значение"<<endl; break;}
				
			string buf2_;
			cout<<"введите город прибытия:";
			cin>>buf2_;
			cout<<endl;	
			if(buf2_ == " "){
				pas.set_city_to(buf2_);
			}else{cout<<"переданно неверное значение"<<endl; break;}
			
			int buf_;
			cout<<"введите тип места 0-купэ, 1-плацкарт:";
			cin>>buf_;
			cout<<endl;
			if(buf_ == 0 or buf_ ==1){
				pas.set_spot(buf_);
			}else{cout<<"переданно неверное значение"<<endl; break;}
			
			flag1 = calcNumber(pas);
			flag2 = calcMesta(pas);
			if(flag1 == 0 or flag == 0){return;}
			}
			Time buf3_;
			Time buf4_;
			for(int i = 0; i < sizeT; i++) {
				if (arrTrain[i].get_number() == pas.trian_nubmer) {
					buf3_ =  arrTrain.get_time_otb();
					buf4_ = arrTrain.get_time_puti();
					break;
				}
			}
			int m = TtoM(gt) - gt.get_d()*1440;
			if(TtoM(buf3_) >= m){
				buf3_.set_d(gt.get_d() + 1);
				pas.set_time_otb(buf3_);
				pas.set_condition(0);
				pas.set_time_prib(buf3_ + buf4_);
			}else{
				buf3_.set_d(gt.get_d());
				pas.set_time_otb(buf3_);
				pas.set_condition(0);
				pas.set_time_prib(buf3_ + buf4_);
			}
			ifstream f;
			f.open(fPassenger);
			for(int i = 0; i < sizeP; i++) {
				f << arrPassenger[i];
			}
			f << pas;
			f.colse();
			return;
		}
	}
}
void Core::rewindTime() {
	int _d, _h, _m;
	Time shift;
	cout << "Пожалуйста, введите время, на которое вы хотите перемотать:" << endl;

	cout << "Дни: ";
	cin >> _d;
	cout << endl;
	shift.set_d(_d);

	while(true) {
		cout << "Часы: ";
		cin >> _h;
		if ((_h < 24) && (_h >= 0)) {
			shift.set_h(_h);
			break;
			cout << endl;
		}
		else {
			cout << "Неверное значение";
		}
	}

        while(true) {
                cout << "Минуты: ";
                cin >> _m;
                if ((_m < 60) && (_m >= 0)) {
                        shift.set_m(_m);
                        break;
                        cout << endl;
                }
                else {
                        cout << "Неверное значение" << endl;
                }
        }


	gt = gt + shift;
	ifstream f;
	f.open(fTime);
	f << gt;
	f.close();
}

int Core::calcNumber(Passenger b) {
	for(int i = 0; i < sizeT; i++) {
		if (arrTrain[i].get_train_city_to() == b.get_city_to() && (arrTrain[i].get_train_city_from() == b.get_city_from) {
			b.train_number() = arrTraint.get_number();
			return 1;
		}
	}
	cout << "Неправильное направление" << endl;
	return 0;
}

void Core::calcTime() {
	//calculation distance
	float x1,x2,y1,y2;
	for(int i = 0; i < sizeC; i++) {
		if (_city_from == arrCity[i].get_name) {
			x1 = arrCity[i].get_city_x;
			y1 = arrCity[i].get_city_y;
		}

                if (_city_to == arrCity[i].get_name) {
                        x2 = arrCity[i].get_city_x;
                        y2 = arrCity[i].get_city_y;
                }

	}
	_distance = sqrt(pow((x1-x2),2) + pow((y1-y2),2));

	//calculation t_puti
	int tm; 
	tm = _distance / (_speed / 60);
	_t_puti = MtoT(tm);

	//calculation t_prib
	_t_prib = _t_otb + _t_puti;
	_t_prib.d = 0;
}

int Core::calcMesta(Passenger t){
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
			cout<<"в плацкарте мест нет";
			return 0;
		}else{
			t.n_vagona=kol/capacity_plackart+1;
			t.n_mesta=kol/vagoni_plackart+1;
		}
	}
	if(t.spot == 0){
		if(kol>=buf.capacity_kupe*buf.vagoni_kupe){
			cout<<"в купе мест нет";
			return 0;
		}else{
			t.n_vagona=kol/capacity_kupe+1;
			t.n_mesta=kol/vagoni_kupe+1;
		}
	}
	return 1;
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
	string b;
	while(f.peek() != EOF){
		getline (f,b);
		size++;
	}
	sizeC=size/3;
	f.close();	
} //Opredelenie razmera massiva gorodov
void Core::sizeTrain(){
	ofsteram f;
	f.open(fTrain);
	size = 0;
	string b;
	while(f.peek() != EOF){
		getline (f,b);
		size++;
	}
	sizeT=size/14;
	f.close();	
}  //Opredelenie razmera massiva reisov
void Core::sizePassenger(){
	ofsteram f;
	f.open(fPassenger);
	size = 0;
	string b;
	while(f.peek() != EOF){
		getline (f,b);
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

Core::Core(char *_fCity, char *_fTrain, char *_fPassenger, char *_fTime) {
	fCity = _fCity;
	fTrain = _fTrain;
	fPassenger = _fPassenger;
	fTime = _fTime;
}

bool Core::isitokay() {
	fstream f;

	f.open(fCity,ios::in);
	if (f) {
		f.close();
	}
	else {
		cout << "Some troubles with the file: " << fCity << endl;
		return false;
	}

        f.open(fTrain,ios::in);
        if (f) {
                f.close();
        }
        else {
                cout << "Some troubles with the file: " << fTrain << endl;
                return false;
        }

        f.open(fPassenger,ios::in);
        if (f) {
                f.close();
        }
        else {
                cout << "Some troubles with the file: " << fPassenger << endl;
                return false;
        }


	bool pust = true;
        f.open(fTime,ios::in);
        if (f) {
		if(f.peek() != EOF) {
			pust = false;
		}
                f.close();
        }
        else {
                cout << "Some troubles with the file: " << fTime << endl;
                return false;
        }
	if(pust) {
		f.open(fTime,ios::out);
		f << "0 0 0";
		f.close();
	}

	return true;
}










