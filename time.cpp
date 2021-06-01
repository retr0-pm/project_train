#include <iostream>
#include <fstream>
#include <string>
#include "core.h"

using namespace std;

int Core::TtoM(Time t) {
	return (t.d * 1440 + t.h * 60 + t.m);
}

Time Core::MtoT(int t) {
	Time buf;
	buf.d = t / 1440;
	buf.h = (t - (buf.d * 1440)) / 60;
	buf.m = t % 60;
	return buf;
}
