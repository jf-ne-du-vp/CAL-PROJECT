#include "Person.h"

Person::Person(){}

Person::Person(string name, double NIF, int destiny): name(name), nif(NIF), destiny(destiny){}


string Person::getName() const{
    return name;
}

void Person::setName(string name){
    this->name = name;
}
double Person::getNIF() const{
    return nif;
}

void Person::setNIF(double nif){
    this->nif = nif;
}

int Person::getDestiny() const{
    return destiny;
}
void Person::setDestiny(int destiny){
    this->destiny = destiny;
}