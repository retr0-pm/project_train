class Train {
private:
    int number; // номер поезда (id маршрута)
    float speed; // скорость поезда
    string from; // город откуда
    string to; // город куда
    float distance; // расстояние между городами(*)
    Time t_otb; // Vremya otbitie
    Time t_prib; // Vremya pribitya (*)
    Time t_puti; // Vremya peremeshenya iz A v B (*)
    int capacity_kupe; // вместительность купе в 1 вагоне
    int capacity_plackart; // вместительность плацкарта в 1 вагоне
    int vagoni_plackart; //кол-во вагонов плацкарт
    int vagoni_kupe;//кол-во вагонов купе
    int cost_kupe; // цена купе
    int cost_plackart; // цена плацкарта
public:

	void outTrain();

	friend ostream &operator<<(ostream &out, const Train &t){
		out<<t.number<<"\n";
		out<<t.speed<<"\n";
		getline(out,t.from);
		getline(out,t.to);
		out<<t.distance<<"\n";
		out<<t.t_otb<<"\n";
		out<<t.t_prib<<"\n";
		out<<t.t_puti<<"\n";
		out<<t.capacity_kupe<<"\n";
		out<<t.capacity_plackart<<"\n";
		out<<t.vagoni_plackart<<"\n";
		out<<t.vagoni_kupe<<"\n";
		out<<t.cost_kupe<<"\n";
		out<<t.cost_plackart<<"\n";
		return out;
	}
	friend istream &operator>>(istream &in, Train &t){

		in>>t.number;
		in>>t.speed;
		in>>t.from;
		in>>t.to;
		in>>t.distance;
		in>>t.t_otb;
		in>>t.t_prib;
		in>>t.t_puti;
		in>>t.capacity_kupe;
		in>>t.capacity_plackart;
		in>>t.vagoni_plackart;
		in>>t.vagoni_kupe;
		in>>t.cost_kupe;
		in>>t.cost_plackart;

		return in;
}
    int get_train_number(){
        return  number;
    }
    float get_train_speed(){
        return  speed;
    }
    string get_train_city_from(){
        return from ;
    }
    string get_train_city_to(){
        return  to;
    }
    float get_distance(){
    	return distance;
    }
    Time get_time_otb() {
	return t_otb;
    }

    Time get_time_prib() {
	return t_prib;
    }
    Time get_time_puti(){
    	return t_puti;
    }
    int get_capacity_kupe(){
    	return capacity_kupe;
    }
    int get_capacity_plackart(){
    	return capacity_plackart;
    }
    int get_train_vagoni_plackart(){
        return  vagoni_plackart;
    }
    int get_train_vagoni_kupe(){
        return  vagoni_kupe;
    }
    int get_train_cost_plackart(){
        return  cost_plackart;
    }
    int get_train_cost_kupe(){
        return  cost_kupe;
    }

    void set_train_number(int a){
            train_number = a;
        }
    void set_train_speed(float a){
            train_speed = a;
        }
    void set_train_from(string a){
            train_from = a;
        }
    void set_train_to(string a){
            train_to = a;
        }
     void set_distance(float a){
	train_speed = a;
     }

    void set_time_otb(Time t) {
	t_otb = t;
    }

    void set_time_prib(Time t) {
	t_prib = t;
    }
    void set_time_puti(Time t) {
    	t_puti = t;
    }
    void set_capacity_kupe(int a){
    	capacity_kupe = a;
    }
    void set_capacity_plackart(int a){
    	capacity_plackart = a;
    }
    void set_train_vagoni_kupe(int a){
            train_vagoni_kupe = a;
        }
    void set_train_vagoni_plackart(int a){
            train_vagoni_plackart = a;
        }
    void set_train_cost_kupe(int a){
            train_cost_kupe = a;
        }
    void set_train_cost_plackart(int a){
            train_cost_plackart = a;
        }
};
