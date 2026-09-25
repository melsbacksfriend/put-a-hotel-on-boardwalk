#include <iostream>
#include <string>

#include "circularlinkedlist.h"

int main()
{
    CircularLinkedList<std::string> monopolyBoard;
    monopolyBoard.insertAtEnd("Go");
    monopolyBoard.insertAtEnd("Mediterranian Avenue");
    monopolyBoard.insertAtEnd("Community Chest");
    monopolyBoard.insertAtEnd("Baltic Avenue");
    monopolyBoard.insertAtEnd("Income Tax");
    monopolyBoard.insertAtEnd("Reading Railroad");
    monopolyBoard.insertAtEnd("Oriental Avenue");
    monopolyBoard.insertAtEnd("Chance");
    monopolyBoard.insertAtEnd("Vermont Avenue");
    monopolyBoard.insertAtEnd("Connecticut Avenue");
    monopolyBoard.insertAtEnd("Jail");
    monopolyBoard.insertAtEnd("St. Charles Place");
    monopolyBoard.insertAtEnd("Electric Company");
    monopolyBoard.insertAtEnd("States Avenue");
    monopolyBoard.insertAtEnd("Virginia Avenue");
    monopolyBoard.insertAtEnd("Pennsylvania Railroad");
    monopolyBoard.insertAtEnd("St. James Place");
    monopolyBoard.insertAtEnd("Community Chest");
    monopolyBoard.insertAtEnd("Tennessee Avenue");
    monopolyBoard.insertAtEnd("New York Avenue");
    monopolyBoard.insertAtEnd("Free Parking");
    monopolyBoard.insertAtEnd("Kentucky Avenue");
    monopolyBoard.insertAtEnd("Chance");
    monopolyBoard.insertAtEnd("Indiana Avenue");
    monopolyBoard.insertAtEnd("Illinois Avenue");
    monopolyBoard.insertAtEnd("B. & O. Railroad");
    monopolyBoard.insertAtEnd("Atlantic Avenue");
    monopolyBoard.insertAtEnd("Ventnor Avenue");
    monopolyBoard.insertAtEnd("Water Works");
    monopolyBoard.insertAtEnd("Marvin Gardens");
    monopolyBoard.insertAtEnd("Go To Jail");
    monopolyBoard.insertAtEnd("Pacific Avenue");
    monopolyBoard.insertAtEnd("North Carolina Avenue");
    monopolyBoard.insertAtEnd("Community Chest");
    monopolyBoard.insertAtEnd("Pennsylvania Avenue");
    monopolyBoard.insertAtEnd("Short Line");
    monopolyBoard.insertAtEnd("Chance");
    monopolyBoard.insertAtEnd("Park Place");
    monopolyBoard.insertAtEnd("Luxury Tax");
    monopolyBoard.insertAtEnd("Boardwalk");
    std::cout << monopolyBoard.getCurrentSpace() << "\n";
    for (int i = 0; i < 42; i++)
    {
        monopolyBoard.rollTheDice();
        std::cout << monopolyBoard.getCurrentSpace() << "\n";
    }
}
