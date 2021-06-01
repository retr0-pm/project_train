#include <iostream>
#include <fstream>
#include <string>
#include "core.h"

using namespace std;

int Core::TtoM(Time t) {
	return (t.get_d() * 1440 + t.get_h() * 60 + t.get_m());
}

Time Core::MtoT(int t) {
	Time buf;
	buf.set_d(t / 1440);
	buf.set_h((t - (buf.get_d() * 1440)) / 60);
	buf.set_m(t % 60);
	return buf;
}
