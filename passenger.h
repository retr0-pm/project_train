class Passenger{
private:
	string name; //
	int age; // возраст пассажира
	int train_number; // номер поезда (id маршрута) (*)
	Time time_ot;
	int spot; //Вид места пассажира, где 0 - купэ, 1 - плацкарт
	int n_vagona; //номер вагона пассажира (*)
	int n_mesta; //номер места пассажира в вагоне (*)
	string city_from; //название города, откуда едет пассажир1
	string city_to; //название города, в который едет пассажир1
	int condition;//состояние пассажира 0-ждет, 1-едет, 2-приехал.
public:
	string get_name(){return name;}
	
	int get_train_number(){return train_number;}
	
	int get_age{return age;}
	
	Time get_time_ot{return time_ot};
	
	int get_spot(){return spot;}
	
	int get_n_vagona(){return n_vagona;}
	
	int get_n_mesta(){return n_mesta;}
	
	string get_city_from(){return city_from;}
	
	string get_city_to(){return city_to;}
	
	int get_condition(){return condition;}
	
	void get_condition(int a){condition =a;}
	void get_n_mesta(int a){n_mesta = a;}
	
	void get_n_vagona(int a){n_vagona = a;}
	
	void set_time_ot(Time t){time_ot = t;}
	
	void set_train_number(int a){ train_number = a;}
	
	void set_name(string a){name = a;}
	
	void set_age(int a){age = a;}
	
	void set_spot(int a){spot = a;}
	
	void set_city_from(string a){city_from = a;}
	
	void set_city_to(string a){city_to = a;}
	
	
	
	friend ostream &operator<<(ostream &out, Passenger &t){
	
		out<<t.name<<"\n";
		out<<t.age<<"\n";
		out<<t.train_numder<<"\n";
		out<<t.time_ot<<"\n";
		out<<t.spot<<"\n";
		out<<t.n_vagona<<"\n";
		out<<t.n_mesta<<"\n";
		out<<t.city_from<<"\n";
		out<<t.city_to<<"\n";
		out<<t.condition<<"\n";
		return out;
		
	} 
	friend istream &operator>>(istream &in, Passenger &t){
		
		getline(in,t.name);
		in>>t.age;
		in>>t.train_number;
		in>>t.time_ot;
		in>>t.spot;
		in>>t.n_vagona;
		in>>t.n_mesta;
		in>>t.city_from;
		in>>t.city_to;
		in>>t.condition;

		return in;
		
	}
};

