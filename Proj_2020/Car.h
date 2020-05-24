#ifndef PROJ_2020_CAR_H
#define PROJ_2020_CAR_H


class Car {
    int seats;

public:
    Car();
    explicit Car(int seats);
    int getSeats() const;
    void setSeats(int seats);
};


#endif //PROJ_2020_CAR_H
