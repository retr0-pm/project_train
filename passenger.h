class Passenger{
private:
	string name; 
	int age; // возраст пассажира
	int train_number; // номер поезда (id маршрута) (*)
	int spot; //Вид места пассажира, где 0 - купэ, 1 - плацкарт
	int n_vagona; //номер вагона пассажира (*)
	int n_mesta; //номер места пассажира в вагоне (*)
	string city_from; //название города, откуда едет пассажир
	string city_to; //название города, в который едет пассажир
public:
	string get_name(){return name;}
	
	int get_train_number(){return train_number;}
	
	int get_age{return age;}
	
	int get_spot(){return spot;}
	
	int get_n_vagona(){return n_vagona;}
	
	int get_n_mesta(){return n_mesta;}
	
	string get_city_from(){return city_from;}
	
	string get_city_to(){return city_to;}
	
	void set_name(string a){name = a;}
	
	void set_age(int a){age = a;}
	
	void set_spot(int a){spot = a;}
	
	void set_city_from(string a){sity_from = a;}
	
	void set_city_to(string a){city_to = a;}
	
	friend ostream &operator<<(ostream &out, Passenger &t){
	
		out<<t.get_name()<<"\n";
		out<<t.get_age()<<"\n";
		out<<t.get_train_numder()<<"\n";
		out<<t.get_spot()<<"\n";
		out<<t.get_n_vagona()<<"\n";
		out<<t.get_n_mesta()<<"\n";
		out<<t.get_city_from()<<"\n";
		out<<t.get_city_to()<<"\n";
		return out;
		
	} 
	friend istream &operator>>(istream &in, Passenger &t){
		
		string buf;
		string n;
		int a;
		int t_n;
		int s;
		int n_v;
		int n_m;
		string c_f;
		string c_t;
		
		getline(in, n);
		in>>a;
		getline(in, buf);
		in>>t_n
		getline(in, buf);
		in>>s;
		getline(in, buf);
		in>>n_v;
		getline(in, buf);
		in>>n_m;
		getline(in, buf);
		getline(in, c_f);
		getline(in, c_t);
		
		t.set_name(n);
		t.set_age(a);
		t.set_train_number(t_n);
		t.set_spot(s);
		t.set_n_vagona(n_v);
		t.set_n_mesta(n_m);
		t.set_sity_from(c_f);
		t.set_city_to(c_t);
		return in;
		
	}
};

