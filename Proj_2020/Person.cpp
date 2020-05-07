#include "Person.h"

Person::Person(){}

Person::Person(string name, double NIF, double destiny): name(name), nif(nif), destiny(destiny){}


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

double Person::getDestiny() const{
    return destiny;
}
void Person::setDestiny(double destiny){
    this->destiny = destiny;
}