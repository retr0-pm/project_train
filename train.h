#include <iostream>
#include <fstream>
#include <string>
#include "time.h"

using namespace std;

class Time;

/**
	\brief Класс, описывающий рейс.
*/
class Train {
private:
    int number;
    float speed;
    string from;
    string to;
    float distance;
    Time *t_otb;
    Time *t_prib;
    Time *t_puti;
    int capacity_kupe;
    int capacity_plackart;
    int vagoni_plackart;
    int vagoni_kupe;
    int cost_kupe;
    int cost_plackart;
public:
	/**
		\brief функция, выводящая информацию об 1-м рейсе
	*/
	void outTrain();
	/**
		\brief перегрузка оператора вывода
		\param stream поток
		\param t  рейс
	*/
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
	/**
		\brief перегрузка оператора ввода
		\param stream поток
		\param t  рейс
	*/
	friend istream &operator>>(istream &in, Train &t){

		in>>t.number;
		in>>t.speed;
		string bufs;
		getline(in,bufs);
		getline(in,t.from);
		getline(in,t.to);
		in>>t.distance;
		in >> *t.t_otb;
		in >> *t.t_prib;
		in >> *t.t_puti;
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
	Time *get_time_otb(){return t_otb;}
	Time *get_time_prib(){return t_prib;}
        Time *get_time_puti(){return t_puti;}
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
	void set_time_otb(Time *t){t_otb = t;}
	void set_time_prib(Time *t){t_prib = t;}
	void set_time_puti(Time *t) {t_puti = t;}
	void set_capacity_kupe(int a){capacity_kupe = a;}
	void set_capacity_plackart(int a){capacity_plackart = a;}
	void set_train_vagoni_kupe(int a){vagoni_kupe = a;}
	void set_train_vagoni_plackart(int a){vagoni_plackart = a;}
	void set_train_cost_kupe(int a){cost_kupe = a;}
	void set_train_cost_plackart(int a){cost_plackart = a;}
};
