#include "time.h"

using namespace std;

int Time::TtoM(Time t) {
	return t.d * 1440 + t.h * 60 + t.m;
}

Time Time::MtoT(int t) {
	Time buf;
	buf.d = t / 1440;
	buf.h = (t - (buf.d * 1440)) / 60;
	buf.m = t % 60;
	return buf;
}
