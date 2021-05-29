class City {
private:
	string city_name; //название города
	float city_x; //кооридната по оси ox этого города
	float city_y; //кооридната по оси oy этого города

public:
	City(string a, float b, float c){
		city_name = a;
		city_x = b;
		city_y =c;
	}
	void a() {
	cout << a;
	}
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
friend ostraem& operator<<(ostream &out, const City &t){

	out<<t.city_name;
	out>>"\n";
	out<<t.city_x;
	out>>"\n";
	out<<t.city_y;
	out>>"\n";
	
}
friend ifstream operator>>(ifstream &in, City &t){
	
	string n;
	float x;
	float y;
	getline(in,n);
	in>>x;
	in>>y;
	set_sity_name(n);
	set_coordinates(x, y);
	
	
}
};
