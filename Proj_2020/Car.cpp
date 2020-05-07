#include "Car.h"

Car::Car() {}

Car::Car(int seats):seats(seats) {}

int Car::getSeats() const{
    return seats;
}

void Car::setSeats(int seats){
    this->seats = seats;
};