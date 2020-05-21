#ifndef PROJ_2020_PERSON_H
#define PROJ_2020_PERSON_H

#include<string>
using namespace std;

class Person {
    string name;
    double nif;
    double destiny;  //id of destiny vertex
public:
    Person();
    Person(string name, double nif, double destiny);
    string getName() const;
    void setName(string name);
    double getNIF() const;
    void setNIF(double nif);
    double getDestiny() const;
    void setDestiny(double destiny);

    /*
     * probably want to add time of arrival to station (need to figure out how to store hour)
     * maybe time waited in station or time from time of arrival till destination
     */
};

#endif //PROJ_2020_PERSON_H
