#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Time {
private:
	int d;
	int h;
	int m;
public:
	Time(int a, int b, int c) {
        	d = a;
        	h = b;
        	m = c;
	}

	Time() {
		d = 0;
		m = 0;
		h = 0;
	}

	int get_d() {return d;}
	int get_h() {return h;}
	int get_m() {return m;}

	void set_d(int _d){d = _d;}
	void set_h(int _h){h = _h;}
	void set_m(int _m){m = _m;}

	friend Time operator+(const Time &t1, const Time &t2) {
		Time result(((t1.d+t2.d)*1440 + (t1.h+t2.h)*60 +(t1.m+t2.m)) /1440,((((t1.h+t2.h)*60+(t1.m+t2.m))/60)%24),((t1.m+t2.m) %60));
		return result;
	}

	friend Time operator-(const Time &t1, const Time &t2) {
		if(((t1.d- t2.d)*1440 + (t1.h-t2.h)*60 +(t1.m-t2.m)) > 0) {
			Time result(((t1.d-t2.d)*1440 + (t1.h-t2.h)*60 +(t1.m-t2.m)) / 1440,((t1.h-t2.h)*60+(t1.m-t2.m))/60,((t1.m-t2.m) %60));
			return result;
		}
		else {
			Time result(((t2.d-t1.d)*1440 + (t2.h-t1.h)*60 +(t2.m-t1.m)) / 1440,((t2.h-t1.h)*60+(t2.m-t1.m))/60,((t2.m-t1.m) %60));
			return result;
		}
	}

	friend ostream &operator<<(ostream &out, const Time &k) {
		out << k.d;
		out << " ";
		out << k.h;
		out << " ";
		out << k.m;
		return out;
	}

	friend istream &operator>>(istream &in, Time &k) {
	in >> k.d >> k.h >> k.m;

	return in;
	}
};

class City {
private:
	string city_name; //название города
	float city_x; //кооридната по оси ox этого города
	float city_y; //кооридната по оси oy этого города

public:
	string get_city_name(){return city_name;}
	float get_city_x(){return city_x;}
	float get_city_y(){return city_y;}

	void set_city_name(string n){city_name = n;}
	void set_coordinates(float a, float b){city_x = a;city_y = b;}

	void outCity();

	friend ostream &operator<<(ostream &out, City &t){

		out<<t.city_name<<"\n";
		out<<t.city_x<<"\n";
		out<<t.city_y<<"\n";

		return out;

	}

	friend istream &operator>>(istream &in, City &t){

		getline(in,t.city_name);
		in>>t.city_x;
		in>>t.city_y;

		return in;
	}
};

class Passenger{
private:
	string name; //
	int age; // возраст пассажира
	int train_number; // номер поезда (id маршрута) (*)
	Time time_ot;//(*)
	Time time_prib;
	int spot; //Вид места пассажира, где 0 - купэ, 1 - плацкарт
	int n_vagona; //номер вагона пассажира (*)
	int n_mesta; //номер места пассажира в вагоне (*)
	string city_from; //название города, откуда едет пассажир1
	string city_to; //название города, в который едет пассажир1
	int condition;//состояние пассажира 0-ждет, 1-едет, 2-приехал.
public:
	string get_name(){return name;}
	int get_train_number(){return train_number;}
	int get_age(){return age;}
	Time get_time_ot(){return time_ot;}
	Time get_time_prib(){return time_ot;}
	int get_spot(){return spot;}
	int get_n_vagona(){return n_vagona;}
	int get_n_mesta(){return n_mesta;}
	string get_city_from(){return city_from;}
	string get_city_to(){return city_to;}
	int get_condition(){return condition;}

	void set_condition(int a){condition = a;}
	void set_n_mesta(int a){n_mesta = a;}
	void set_n_vagona(int a){n_vagona = a;}
	void set_time_ot(Time t){time_ot = t;}
	void set_time_prib(Time t){time_prib = t;}
	void set_train_number(int a){ train_number = a;}
	void set_name(string a){name = a;}
	void set_age(int a){age = a;}
	void set_spot(int a){spot = a;}
	void set_city_from(string a){city_from = a;}
	void set_city_to(string a){city_to = a;}

	void outPassenger();

	friend ostream& operator<<(ostream &out, Passenger &t){

		out<<t.name <<"\n";
		out<<t.age <<"\n";
		out<<t.train_number <<"\n";
		out<<t.time_ot <<"\n";
		out<<t.time_prib <<"\n";
		out<<t.spot <<"\n";
		out<<t.n_vagona <<"\n";
		out<<t.n_mesta <<"\n";
		out<<t.city_from <<"\n";
		out<<t.city_to <<"\n";
		out<<t.condition <<"\n";

		return out;

	}
	friend istream& operator>>(istream &in, Passenger &t){

		getline(in,t.name);
		in>>t.age;
		in>>t.train_number;
		int a,b,c;
		in >> a >> b >> c;
		t.time_ot.set_d(a);
                t.time_ot.set_h(b);
                t.time_ot.set_m(c);
                in >> a >> b >> c;
                t.time_prib.set_d(a);
                t.time_prib.set_h(b);
                t.time_prib.set_m(c);
		in>>t.spot;
		in>>t.n_vagona;
		in>>t.n_mesta;
		in>>t.city_from;
		in>>t.city_to;
		in>>t.condition;

		return in;

	}
};

class Train {
private:
    int number; // номер поезда (id маршрута)
    float speed; // скорость поезда
    string from; // город откуда
    string to; // город куда
    float distance; // расстояние между городами(*)
    Time t_otb; // Vremya otbitie
    Time t_prib; // Vremya pribitya (*)
    Time t_puti; // Vremya peremeshenya iz A v B (*)
    int capacity_kupe; // вместительность купе в 1 вагоне
    int capacity_plackart; // вместительность плацкарта в 1 вагоне
    int vagoni_plackart; //кол-во вагонов плацкарт
    int vagoni_kupe;//кол-во вагонов купе
    int cost_kupe; // цена купе
    int cost_plackart; // цена плацкарта
public:
	void outTrain();

	friend ostream &operator<<(ostream &out, const Train &t){

		out<<t.number<<"\n";
		out<<t.speed<<"\n";
		out<<t.from << "\n";
		out<<t.to << "\n";
		out<<t.distance<<"\n";
		out<<t.t_otb<<"\n";
		out<<t.t_prib<<"\n";
		out<<t.t_puti<<"\n";
		out<<t.capacity_kupe<<"\n";
		out<<t.capacity_plackart<<"\n";
		out<<t.vagoni_plackart<<"\n";
		out<<t.vagoni_kupe<<"\n";
		out<<t.cost_kupe<<"\n";
		out<<t.cost_plackart<<"\n";

		return out;
	}

	friend istream &operator>>(istream &in, Train &t){

		in>>t.number;
		in>>t.speed;
		string bufs;
		getline(in,bufs);
		getline(in,t.from,'\n');
		getline(in,t.to,'\n');
		in>>t.distance;
		int a,b,c;
		in >> a >> b >> c;
		t.t_otb.set_d(a);
		t.t_otb.set_h(b);
		t.t_otb.set_m(c);
                in >> a >> b >> c;
                t.t_prib.set_d(a);
                t.t_prib.set_h(b);
                t.t_prib.set_m(c);
                in >> a >> b >> c;
                t.t_puti.set_d(a);
                t.t_puti.set_h(b);
                t.t_puti.set_m(c);
		in>>t.capacity_kupe;
		in>>t.capacity_plackart;
		in>>t.vagoni_plackart;
		in>>t.vagoni_kupe;
		in>>t.cost_kupe;
		in>>t.cost_plackart;

		return in;
	}

	int get_train_number(){return number;}
	float get_train_speed(){return speed;}
	string get_train_city_from(){return from;}
	string get_train_city_to(){return to;}
	float get_distance(){return distance;}
	Time get_time_otb(){return t_otb;}
	Time get_time_prib(){return t_prib;}
        Time get_time_puti(){return t_puti;}
        int get_capacity_kupe(){return capacity_kupe;}
        int get_capacity_plackart(){return capacity_plackart;}
	int get_train_vagoni_plackart(){return  vagoni_plackart;}
	int get_train_vagoni_kupe(){return  vagoni_kupe;}
	int get_train_cost_plackart(){return  cost_plackart;}
	int get_train_cost_kupe(){return  cost_kupe;}

	void set_train_number(int a){number = a;}
	void set_train_speed(float a){speed = a;}
	void set_train_from(string a){from = a;}
	void set_train_to(string a){to = a;}
	void set_distance(float a){distance = a;}
	void set_time_otb(Time t){t_otb = t;}
	void set_time_prib(Time t){t_prib = t;}
	void set_time_puti(Time t) {t_puti = t;}
	void set_capacity_kupe(int a){capacity_kupe = a;}
	void set_capacity_plackart(int a){capacity_plackart = a;}
	void set_train_vagoni_kupe(int a){vagoni_kupe = a;}
	void set_train_vagoni_plackart(int a){vagoni_plackart = a;}
	void set_train_cost_kupe(int a){cost_kupe = a;}
	void set_train_cost_plackart(int a){cost_plackart = a;}
};
