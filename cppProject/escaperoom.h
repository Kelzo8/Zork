#ifndef ESCAPEROOM_H
#define ESCAPEROOM_H

#include <QMainWindow>
#include <QtWidgets>
#include <iostream>
#include <exception>
#include "room.h"
#include "specialroom.h"

class EscapeRoom : public QMainWindow {
    Q_OBJECT
public:
    EscapeRoom(QWidget *parent = nullptr);

private slots:
    void processInput();
    void showCurrentRoom(); // Declaration added

private:
    // Programmer-defined exception class
    class MathError : public std::exception {
    public:
        const char* what() const noexcept override {
            return "Math error occurred!";
        }
    };

    // UI elements
    QLabel *roomTextLabel;
    QLabel *equationTextLabel;
    QLineEdit *inputLineEdit;
    QPushButton *submitButton;

    // Index of the current room
    int currentRoomIndex;

    // List of room pointers
    QList<Room*> rooms;

    // Function to initialize rooms
    void initializeRooms(); // Declaration added
};

#endif // ESCAPEROOM_H
