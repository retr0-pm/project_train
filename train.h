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
    Time get_time_otb() {
	return time_otb;
    }

    Time get_time_prib() {
	return time_prib;
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
        if (a > 0.0){
            train_speed = a;
            }else{
                cout<<"не корректно"<<endl;
                }
        }
    void set_train_from(string a){
        if (a != " "){
            train_from = a;
            }else{
                cout<<"не корректно"<<endl;
                }
        }
    void set_train_to(string a){
        if (a != " "){
            train_to = a;
            }else{
                cout<<"не корректно"<<endl;
                }
        }

    void set_t_otb(Time t) {
	t_otb = t;
    }

    void set_t_prib(Time t) {
	t_prib = t;
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
