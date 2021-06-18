#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Time;

/**
	\brief Класс описывает пассажира.
*/

class Passenger{
private:
	string name;
	int age;
	int train_number;
	Time *time_ot;
	Time *time_prib;
	int spot;
	int n_vagona;
	int n_mesta;
	string city_from;
	string city_to;
	int condition;
public:
	string get_name(){return name;}
	int get_train_number(){return train_number;}
	int get_age(){return age;}
	Time *get_time_ot(){return time_ot;}
	Time *get_time_prib(){return time_prib;}
	int get_spot(){return spot;}
	int get_n_vagona(){return n_vagona;}
	int get_n_mesta(){return n_mesta;}
	string get_city_from(){return city_from;}
	string get_city_to(){return city_to;}
	int get_condition(){return condition;}

	void set_condition(int a){condition = a;}
	void set_n_mesta(int a){n_mesta = a;}
	void set_n_vagona(int a){n_vagona = a;}
	void set_time_ot(Time *t){time_ot = t;}
	void set_time_prib(Time *t){time_prib = t;}
	void set_train_number(int a){ train_number = a;}
	void set_name(string a){name = a;}
	void set_age(int a){age = a;}
	void set_spot(int a){spot = a;}
	void set_city_from(string a){city_from = a;}
	void set_city_to(string a){city_to = a;}

	/**
		\brief функция, выводящая на экран иформацию об 1-м пассажире 
	*/
	void outPassenger();
	/**
		\brief перегрузка оператора вывода
		\param stream поток
		\param t  пассажир
	*/
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
	/**
		\brief перегрузка оператора ввода
		\param stream поток
		\param t  пассажир
	*/
	friend istream& operator>>(istream &in, Passenger &t){

		string b;

		getline(in,t.name);
		in>>t.age;
		in>>t.train_number;
		Time *bt = new Time;
		in >> *bt;
		t.time_ot = bt;
		delete bt;
		Time *bt1 = new Time;
		in >> *bt1;
		t.time_prib = bt1;
		delete bt1;
		in>>t.spot;
		in>>t.n_vagona;
		in>>t.n_mesta;
		getline(in, b);
		getline(in,t.city_from);
		getline(in,t.city_to);
		in>>t.condition;

		return in;

	}
};
