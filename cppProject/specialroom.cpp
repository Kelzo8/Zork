#ifndef SPECIALROOM_H
#define SPECIALROOM_H

#include "room.h"
#include <iostream>

class SpecialRoom : public Room {
public:
    // Constructor for SpecialRoom
    SpecialRoom(QString name, QString description, QString equation, double expectedResult) :
        Room(std::move(name), std::move(description), std::move(equation), expectedResult) {}

    // Override specialAbility function
    void specialAbility() const override {
        std::cout << "Correct answer!" << std::endl;
    }
};

#endif // SPECIALROOM_H
