#include "Car.h"

Car::Car() {}

Car::Car(int seats, int ID):seats(seats), ID(ID) {}

int Car::getSeats() const{
    return seats;
}

void Car::setSeats(int seats){
    this->seats = seats;
}

int Car::getID() const{
    return this->ID;
}


void Car::setID(int ID) {
    this->ID = ID;
}