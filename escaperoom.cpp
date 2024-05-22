// escaperoom.cpp
#include "escaperoom.h"
#include "specialroom.h"

EscapeRoom::EscapeRoom(QWidget *parent) : QMainWindow(parent), currentRoomIndex(0) {
    setWindowTitle("Math Maze Mysteries");
    setFixedSize(600, 400);

    // Create main layout and set it as central widget
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    centralWidget->setLayout(mainLayout);

    // Create labels and input elements
    roomTextLabel = new QLabel;
    roomTextLabel->setAlignment(Qt::AlignCenter);
    roomTextLabel->setStyleSheet("color: #FFFFFF; font-size: 18px;");
    mainLayout->addWidget(roomTextLabel);

    equationTextLabel = new QLabel;
    equationTextLabel->setAlignment(Qt::AlignCenter);
    equationTextLabel->setStyleSheet("color: #FFFFFF; font-size: 16px;");
    mainLayout->addWidget(equationTextLabel);

    QHBoxLayout *inputLayout = new QHBoxLayout;
    mainLayout->addLayout(inputLayout);

    inputLineEdit = new QLineEdit;
    inputLineEdit->setPlaceholderText("Enter solution");
    inputLineEdit->setStyleSheet("background-color: #FFFFFF; color: #000000; font-size: 16px;");
    inputLayout->addWidget(inputLineEdit);

    submitButton = new QPushButton("Submit");
    submitButton->setStyleSheet("background-color: #008000; color: #FFFFFF; font-size: 16px;");
    inputLayout->addWidget(submitButton);

    // Connect submit button click signal to processInput slot
    connect(submitButton, &QPushButton::clicked, this, &EscapeRoom::processInput);

    initializeRooms(); // Initialize rooms
    showCurrentRoom(); // Show initial room
}

void EscapeRoom::processInput() {
    QString inputText = inputLineEdit->text();
    bool success = false;

    try {
        // Check if the input matches the expected result for the current room
        if (inputText.toDouble() == rooms[currentRoomIndex]->expectedResult) {
            currentRoomIndex++;
            // If there are more rooms, show the next room
            if (currentRoomIndex < rooms.size()) {
                showCurrentRoom();
                success = true;
            } else {
                // If it's the last room, show congratulations message and close
                QMessageBox::information(this, "Congratulations", "You escaped the last room!");
                close();
                return;
            }
        }

        if (!success) {
            // Throw MathError if input is incorrect
            throw MathError(); // Throw programmer defined exception
        }
    } catch (const std::exception& e) {
        // Display warning message for math error
        QMessageBox::warning(this, "Error", e.what());
    }

    // Clear input line edit
    inputLineEdit->clear();
}

void EscapeRoom::showCurrentRoom() {
    // Get pointer to the current room
    const Room *currentRoom = rooms[currentRoomIndex];

    // Update labels with room information
    roomTextLabel->setText("<h2 style='color: #00008B;'>" + currentRoom->name + "</h2><p style='color: #00008B;'>" + currentRoom->description + "</p>");
    equationTextLabel->setText("<p style='color: #00008B;'>Equation: " + currentRoom->equation + "</p>");

    // Call specialAbility function of current room
    currentRoom->specialAbility(); // Call virtual function
}

void EscapeRoom::initializeRooms() {
    // Add rooms to the list
    rooms.append(new SpecialRoom("Room 1", "You are in the first room. Solve the equation to proceed.", "2 * 3", 6.0));
    rooms.append(new SpecialRoom("Room 2", "You are in the second room. Solve the equation to proceed.", "5 + 8", 13.0));
    rooms.append(new SpecialRoom("Room 3", "You are in the third room. Solve the equation to proceed.", "10 + 8", 18.0));
    rooms.append(new SpecialRoom("Room 4", "You are in the fourth room. Solve the equation to proceed.", "50/5", 10.0));
    rooms.append(new SpecialRoom("Room 5", "You are in the fifth room. Solve the equation to proceed.", "2x+5=15 what is the value of x?", 5.0));
    rooms.append(new SpecialRoom("Room 6", "You are in the sixth room. Solve the equation to proceed.", "(50/5)-5", 5.0));
    rooms.append(new SpecialRoom("Room 7", "You are in the sevent room. Solve the equation to proceed.", "50 x 2", 100.0));
    rooms.append(new SpecialRoom("Room 8", "You are in the eight room. Solve the equation to proceed.", "2, 4, 8, 16, 32.. what's the next number", 64.0));
    rooms.append(new SpecialRoom("Room 9", "You are in the ninth room. Solve the equation to proceed.", "what percent did the student get if they got 63 out of 90", 70.0));
}
