#include <string>
#include <iostream>
#include "stack.h"
#include "queue.h"

using namespace std;

int main() {
    string givenInfix, userChoice, userChoice2, givenString;
    Infix object;
    queue myQueue;
    bool check = true;


    cout << "Welcome, would you like to:\n1. Convert infix to postfix\n2. Implemented stack\n";
    cin >> userChoice;
    getline(cin, userChoice2); 

    if (userChoice == "1") { // If their input is 1, it outputs the below
        cout << "Enter an infix expression: ";
        getline(cin, givenInfix);

        cout << "Your postfix expression is: " << object.convertToPostfix(givenInfix) << "\n";
    }

    else if (userChoice == "2") { // If their input is 2, it outputs the below
        while (check == true) {
            cout << "Welcome, would you like to:\n1. Insert a new element\n2. Remove front element\n3. Return front element\n4. Check if queue is empty\n5. Return number of elements\n6. Quit\n";
            cin >> userChoice2;
            switch (stoi(userChoice2)) {
            case 1:
                cout << "What string would you like to insert?: ";
                cin >> givenString;
                myQueue.insertRear(givenString); // inserts string
                break;
            case 2:
                cout << "Removed " << myQueue.removeFront() << " from front of queue.\n"; 
                break;
            case 3:
                cout << "The front element is: " << myQueue.popFront() << "\n";
                break;
            case 4:
                if (myQueue.queueEmpty()) {
                    cout << "Queue is empty.\n";
                }
                else {
                    cout << "Queue is not empty.\n";
                }
                break;
            case 5:
                cout << "There are " << myQueue.queueSize() << " elements.\n";
                break;
            case 6:
                cout << "Quitting\n";
                check = false;
                break;
            default:
                cout << "Invalid. Try again.\n";
            }
        }
    }

    else {
        cout << "Invalid answer.";
    }

    return 0;
}