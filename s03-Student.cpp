#include <iostream>
#include <string>
#include <sstream>
#include "Student.h"

auto student::to_string() const -> std::string {
std::string pom =" imię: " + imie + "\n nazwisko: " + nazwisko + "\n semestr:" + semestr + "\n indeks:" + indeks;
return pom;
}




int main(){

student ja{"Ola", "Bondos", "1", "s25337"};
std::cout<<ja.to_string();

}
