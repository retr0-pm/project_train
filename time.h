#include <fstream>
#include <iostream>
#include <string>

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

Time();

int get_d() {return d;}
int get_h() {return h;}
int get_m() {return m;}
void set_d(int _d){d = _d;}
void set_h(int _h){h = _h;}
void set_m(int _m){m = _m;}

friend Time operator+(const Time &t1, const Time &t2) {
	Time result(((t1.d+t2.d)*1440 + (t1.h+t2.h)*60 +(t1.m+t2.m)) /1440,((t1.h+t2.h)*60+(t1.m+t2.m))/60,((t1.m+t2.m) %60));
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
	out << k.d << k.h << k.m;
	return out;
}

friend istream &operator>>(istream &in, Time &k) {

	in >> k.d >> k.h >> k.m;

	return in;
}

};
