#include <iostream>
#include <string>
#include <vector>

// Forward declaration
class Entity;

// Abstract class representing a game entity
class Entity {
public:
    virtual void interact() const = 0;  // Pure virtual function
    virtual ~Entity() {}  // Virtual destructor
};

// Class representing items
class Item : public Entity {
public:
    Item(const std::string& name, const std::string& description) : name(name), description(description) {}
    std::string getName() const { return name; }
    std::string getDescription() const { return description; }
    // Implement virtual function
    void interact() const override {
        std::cout << "You interact with " << name << ": " << description << std::endl;
    }
private:
    std::string name;
    std::string description;
};

// Class representing rooms
class Room : public Entity {
public:
    Room(const std::string& name, const std::string& description) : name(name), description(description) {}
    void addItem(Item* item) {
        items.push_back(item);
    }
    std::string getName() const { return name; }
    std::string getDescription() const { return description; }
    std::vector<Item*> getItems() const { return items; }
    // Implement virtual function
    void interact() const override {
        std::cout << "You are in " << name << ".\n";
        std::cout << description << "\nItems in Room:\n";
        for (const Item* item : items) {
            std::cout << item->getName() << ": " << item->getDescription() << std::endl;
        }
    }
private:
    std::string name;
    std::string description;
    std::vector<Item*> items;
};

// Main game class
class Game {
public:
    Game() {
        // Create rooms
        entrance = new Room("Entrance", "You are standing at the entrance of the escape room. There are multiple rooms to explore.");
        livingRoom = new Room("Living Room", "A cozy living room with a fireplace.");
        kitchen = new Room("Kitchen", "A spacious kitchen with modern appliances.");
        bedroom = new Room("Bedroom", "A comfortable bedroom with a large bed.");
        exitRoom = new Room("Exit", "Congratulations! You have found the exit.");

        // Create items
        key = new Item("Key", "A small golden key.");
        book = new Item("Book", "An old book with a worn cover.");
        flashlight = new Item("Flashlight", "A powerful flashlight.");

        // Add items to rooms
        entrance->addItem(key);
        livingRoom->addItem(book);
        kitchen->addItem(flashlight);

        // Initialize game state
        currentRoom = entrance;
    }

    ~Game() {
        // Clean up memory
        delete entrance;
        delete livingRoom;
        delete kitchen;
        delete bedroom;
        delete exitRoom;
        delete key;
        delete book;
        delete flashlight;
    }

    void play() {
        std::cout << "Welcome to the Escape Room!\n";
        while (true) {
            std::cout << "\nYou are now in the " << currentRoom->getName() << ".\n";
            currentRoom->interact();
            if (currentRoom == exitRoom && hasKey) {
                std::cout << "\nCongratulations! You have completed the game.\n";
                break;
            }
            std::cout << "\nWhere would you like to go next? Enter room name (living room, kitchen, bedroom) or type 'exit' to quit: ";
            std::string input;
            std::cin >> input;
            if (input == "exit") {
                std::cout << "Exiting the game...\n";
                break;
            } else if (input == "living room") {
                currentRoom = livingRoom;
            } else if (input == "kitchen") {
                currentRoom = kitchen;
            } else if (input == "bedroom") {
                currentRoom = bedroom;
            } else {
                std::cout << "Invalid room name. Please try again.\n";
            }
            if (currentRoom == exitRoom && currentRoom->getItems().empty()) {
                std::cout << "You found the key! Now you can unlock the exit...\n";
                hasKey = true;
            }
        }
    }

private:
    Room* entrance;
    Room* livingRoom;
    Room* kitchen;
    Room* bedroom;
    Room* exitRoom;
    Room* currentRoom;
    Item* key;
    Item* book;
    Item* flashlight;
    bool hasKey = false;
};

int main() {
    Game game;
    game.play();
    return 0;
}