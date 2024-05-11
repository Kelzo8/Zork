#ifndef ROOM_H
#define ROOM_H

#include <QString>

class Room {
     friend void friendFunction(Room&);
public:
    QString name;
    QString description;
    QString equation;
    double expectedResult;
    unsigned int secretCode : 4; // Bit field for secret code
    union {
        int intData;
        double doubleData;
    };

    // Constructor for the Room struct
    Room(QString name, QString description, QString equation, double expectedResult) :
        name(std::move(name)), description(std::move(description)), equation(std::move(equation)),
        expectedResult(expectedResult), secretCode(0), intData(0) {}

    // Virtual destructor
    virtual ~Room() {}

    // Virtual function for special ability
    virtual void specialAbility() const = 0; // Virtual function


    void friendFunction(Room& room) {
        // Access private members of Room class
        // You can access the private members of Room here since friendFunction is declared as a friend function in the Room class
        // For example:
        room.name = "New Name"; // Accessing private member name
    }
};

#endif // ROOM_H
