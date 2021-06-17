#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Time;

/**
	\brief Класс описывающий пункт.
*/
class City {
private:
	string city_name;
	float city_x;
	float city_y;

public:
	string get_city_name(){return city_name;}
	float get_city_x(){return city_x;}
	float get_city_y(){return city_y;}

	void set_city_name(string n){city_name = n;}
	void set_coordinates(float a, float b){city_x = a;city_y = b;}


	/**
		\brief функция, выводящая на экран информацию об 1-м городе 
	*/
	void outCity();
	/**
		\brief перегруза оператора вывода
		\param steram поток данных
		\param	t  пункт
	*/
	friend ostream &operator<<(ostream &out, City &t){

		out<<t.city_name<<"\n";
		out<<t.city_x<<"\n";
		out<<t.city_y<<"\n";

		return out;

	}
	/**
		\brief перегрузки перегрузка ввода
		\param steram поток данных
		\param	t  пункт
	*/
	friend istream &operator>>(istream &in, City &t){

		getline(in,t.city_name);
		in>>t.city_x;
		in>>t.city_y;

		return in;
	}
};
