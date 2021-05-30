#include <iostream>

/*void find_n_mesta(){
	int buf;
	int tr_num = -1;
	for (int i = 0; i < size_passenger; i++){
		if (arrPassenger[size_passenger-1].get_spot == arrPassenger[i].get_spot ){buf++;}
	}
	
	if (capacity_kupe*vagoni_cupe = buf){
		cour<<"No place";
	}
	else {
		n_mes
		buf%vagoni_kupe+1
		{
		
}*/

void calcPosition(Passanger t){ //we are have this in core.cpp after the moment yor are see
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
	
void Core::searchCity(){
	string buf;
	cout << "Enter the name of city: ";
	cin.getline(buf,256,'\n');
	cout << endl;
	for (i=0, i<sizeC, i++){
		if (buf == arrCity[i].get_city_name){
			cout << i << ". ";
			cout <<"City name: " << arrCity[i].get_city_name;
			cout <<", City x: " << arrCity[i].get_city_x;
			cout <<", City y: " << arrCity[i].get_city_y << endl;
			break;
		}
	}
	
void Core::outputCity(){
	for (i=0, i<sizeC, i++){
		cout<<i+1<<". "<<arrCity[i].get_city_name<<" ("<<arrCity[i].get_city_x<<";"<<arrCity[i].get_city_y;<<")";
	}
}

void Core::addCity(){
	string buf_n;
	float buf_x;
	float buf_y;
	arrCity[sizeC++].set_city_name(buf_n);
	arrCity[sizeC++].set_coordinates(buf_x, buf_y);
}

void Core::changeCity(){
	
		
		
	
	
		
		
		
			
