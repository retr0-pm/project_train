class Passenger{
private:
	string name; 
	int train_number; // номер поезда (id маршрута) (*)
	int age; // возраст пассажира
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
	
};

