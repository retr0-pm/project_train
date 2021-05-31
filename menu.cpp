#include <iostream>

using namespace std;

Menu::Menu() {
        system("clear");
        system("sl -F");
        system("clear");
        system("figlet -ctk -f slant Welcome to the PROJECT TRAIN");
}

Menu::~Menu() {
        system("clear");
        system("sl -l");
        system("clear");
        system("figlet -ctk -f slant Come again :)");
}

Menu::Start() {

