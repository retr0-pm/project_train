#include <iostream>
#include <fstream>

using namespace std;

/**
	\brief Класс времени
*/
class Time {
private:
	int d;
	int h;
	int m;
public:
	/**
		\brief конструктор с параметрами
	*/
	Time(int a, int b, int c) {
        	d = a;
        	h = b;
        	m = c;
	}
	/**
		\brief конструктор по умолчанию
	*/
	Time() {
		d = 0;
		h = 0;
		m = 0;
	}

	int get_d() {return d;}
	int get_h() {return h;}
	int get_m() {return m;}

	void set_d(int _d){d = _d;}
	void set_h(int _h){h = _h;}
	void set_m(int _m){m = _m;}

	/**
		\brief перегрузка оператора сложения
		\param t1 время
		\param t2 время
	*/
	friend Time operator+(const Time &t1, const Time &t2) {
		Time result(((t1.d+t2.d)*1440 + (t1.h+t2.h)*60 +(t1.m+t2.m)) /1440,((((t1.h+t2.h)*60+(t1.m+t2.m))/60)%24),((t1.m+t2.m) %60));
		return result;
	}
	/**
		\brief перегрузка оператора вычитания
		\param t1 время
		\param t2 время
	*/
	friend Time operator-(const Time &t1, const Time &t2) {
		if(((t1.d- t2.d)*1440 + (t1.h-t2.h)*60 +(t1.m-t2.m)) > 0) {
			Time result(((t1.d-t2.d)*1440 + (t1.h-t2.h)*60 +(t1.m-t2.m)) / 1440,((((t1.h-t2.h)*60+(t1.m-t2.m))/60)%24),((t1.m-t2.m) %60));
			return result;
		}
		else {
			Time result(((t2.d-t1.d)*1440 + (t2.h-t1.h)*60 +(t2.m-t1.m)) / 1440,((((t2.h-t1.h)*60+(t2.m-t1.m))/60)%24),((t2.m-t1.m) %60));
			return result;
		}
	}
	/**
		\brief перегрузка оператора вывода
		\param stream поток
		\param t  время
	*/
	friend ostream &operator<<(ostream &out, const Time &k) {
		out << k.d;
		out << " ";
		out << k.h;
		out << " ";
		out << k.m;
		return out;
	}
	/**
		\brief перегрузка оператора ввода
		\param stream поток
		\param t  время
	*/
	friend istream &operator>>(istream &in, Time &k) {
	in >> k.d >> k.h >> k.m;

	return in;
	}

};
