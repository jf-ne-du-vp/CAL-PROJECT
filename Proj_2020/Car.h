#ifndef PROJ_2020_CAR_H
#define PROJ_2020_CAR_H


/**
 * @brief Car class used to structure cars
 */
class Car {

    /**
     * Number of seats on car
     */
    int seats;

    /**
     * Car ID
     */
    int ID;

public:

    /**
     * @brief Construct a new car object
     */
    Car();

    /**
     * @brief Constructs a new car object
     * @param seats Number of seats in car
     * @param ID Car ID
     */
    explicit Car(int seats, int ID);

    /**
     * @brief Returns number of car seats (between 4 and 8)
     * @return number of car seats
     */
    int getSeats() const;

    /**
     * @brief Set number of car seats (between 4 and 8)
     * @param seats Number of car seats
     */
    void setSeats(int seats);

    /**
     * @brief Returns car ID
     * @return Car ID
     */
    int getID() const;

    /**
     * @brief Set car ID
     * @param ID Car ID
     */
    void setID(int ID);
};


#endif //PROJ_2020_CAR_H
