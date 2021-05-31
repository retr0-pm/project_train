class City {
private:
	string city_name; //название города
	float city_x; //кооридната по оси ox этого города
	float city_y; //кооридната по оси oy этого города

public:
	string get_city_name(){
		return  name;
	}
	float get_city_x(){
		return city_x;
	}
	float get_city_y(){
		return city_y;
	}
	void set_city_name(string n){
		city_name = n;
	}

void set_coordinates(float a, float b){
	city_x = a;
	city_y = b;
}

void outCity();

friend ostraem &operator<<(ostream &out, const City &t){

	out<<t.city_name<<"\n";
	out<<t.city_x<<"\n";
	out<<t.city_y<<"\n";
	return out;
	
}
friend istream &operator>>(ifstream &in, City &t){
	
	getline(in,t.city_name);
	in>>t.city_x;
	in>>t.city_y;
	return in;
	
}
};
