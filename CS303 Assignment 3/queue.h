#include <string>

using namespace std;

class Node {
public:
    string data;
    Node* next;

    Node(string value) { // Constructor
        data = value;
        next = nullptr;
    }

    ~Node() { // Destructor
        delete next;
    }
};

class queue {
public:
    void insertRear(string value);
    string popFront();
    string removeFront();
    bool queueEmpty();
    int queueSize();
    queue(); //

private:
    int queuesize;
    Node* head;
    Node* tail;
}; 
#pragma once
