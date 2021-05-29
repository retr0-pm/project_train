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
friend ostream &operator<<(ostream &out, const Train &t){
		out<<t.get_train_number()<<"\n";
		out<<t.get_train_speed()<<"\n";
		out<<t.get_train_sity_from()<<"\n";
		out<<t.get_train_sity_to()<<"\n";
		out<<t.get_distance()<<"\n";
		out<<t.get_time_otb()<<"\n";
		out<<t.get_time_prib()<<"\n";
		out<<t.get_time_puti()<<"\n";
		out<<t.get_capacity_kupe()<<"\n";
		out<<t.get_capacity_plackart<<"\n";
		out<<t.get_train_vagoni_plackart()<<"\n";
		out<<t.get_train_vagoni_kupe()<<"\n";
		out<<t.get_train_cost_kupe()<<"\n";
		out<<t.get_train_cost_plackart()<<"\n";
		return out;
		
	}
friend istream &operator>>(istream &in, Train &t){
    in>>number;
    in>>speed;
    in>>from;
    in>>to;
    in>>distance;
    in>>t_otb;
    in>>t_prib;
    in>>t_puti;
    in>>capacity_kupe;
    in>>capacity_plackart;
    in>>vagoni_plackart;
    in>>vagoni_kupe;
    in>>cost_kupe;
    in>>cost_plackart;
	return in;
}
    int get_train_number(){
        return  number;
    }
    float get_train_speed(){
        return  speed;
    }
    string get_train_sity_from(){
        return from ;
    }
    string get_train_sity_to(){
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
