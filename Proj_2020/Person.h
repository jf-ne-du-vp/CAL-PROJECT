#ifndef PROJ_2020_PERSON_H
#define PROJ_2020_PERSON_H

#include<string>

using namespace std;

/**
 * @brief Person class used to structure person
 */
class Person {

    /**
     * Person name
     */
    string name;

    /**
     * Person NIF
     */
    double nif;

    /**
     * Destination node ID
     */
    int destiny;
public:

    /**
     * @brief Constructor of new person object
     */
    Person();


    /**
     * @brief Constructor of new perosn object
     * @param name Person name
     * @param nif Person nif
     * @param destiny Person destination node ID
     */
    Person(string name, double nif, int destiny);


    /**
     * @brief Get person name
     * @return Person name
     */
    string getName() const;


    /**
     * @brief Set person name
     * @param name Person name
     */
    void setName(string name);


    /**
     * @brief get person NIF
     * @return Person NIF
     */
    double getNIF() const;


    /**
     *  @brief Set Person NIF
     * @param nif Person NIF
     */
    void setNIF(double nif);


    /**
     * @brief Get person Destination node ID
     * @return Person destination node ID
     */
    int getDestiny() const;


    /**
     * @brief Set Person destination node ID
     * @param destiny Person destination ID
     */
    void setDestiny(int destiny);

    /*
     * probably want to add time of arrival to station (need to figure out how to store hour)
     * maybe time waited in station or time from time of arrival till destination
     */
};

#endif //PROJ_2020_PERSON_H
