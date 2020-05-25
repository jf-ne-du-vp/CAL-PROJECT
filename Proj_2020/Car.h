#ifndef PROJ_2020_CAR_H
#define PROJ_2020_CAR_H


class Car {
    int seats;
    int ID;

public:
    Car();
    explicit Car(int seats, int ID);
    int getSeats() const;
    void setSeats(int seats);
    int getID() const;
    void setID(int ID);
};


#endif //PROJ_2020_CAR_H
