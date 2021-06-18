#include <iostream>
#include <fstream>
#include <string>
#include "core.h"

using namespace std;
/**
	\brief Класс, выполняющий роль меню
*/
class Menu {
public:
	Menu();
	void Start(Core &obj);
	~Menu();
};

