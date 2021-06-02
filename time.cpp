#include <iostream>
#include <fstream>
#include <string>
#include "core.h"

using namespace std;

int Core::TtoM(Time t) {
	int res;
	res = t.get_d() * 1440 + t.get_h() * 60 + t.get_m();
	return res;
}

Time Core::MtoT(int t) {
	Time buf;
	buf.set_d(t / 1440);
	buf.set_h((t - (buf.get_d() * 1440)) / 60);
	buf.set_m(t % 60);
	return buf;
}
