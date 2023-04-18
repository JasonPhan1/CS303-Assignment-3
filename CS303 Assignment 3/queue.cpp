#include <string>
#include <iostream>
#include "queue.h"

using namespace std;

void queue::insertRear(string value) {
    Node* newNode = new Node(value);

    if (queueEmpty() == true) { // If the queue is empty, set our head and tail to our new node
        head = tail = newNode;
    }
    else { // If not, move our tail to the newest addition.
        tail->next = newNode;
        tail = newNode;
    }
    queuesize++;
    cout << "Operation completed.\n";
}

string queue::popFront() {
    if (queueEmpty() == true) { // Can't return nothing.
        cout << "Queue is empty. Cannot return data.";
    }
    else { // Simply return the data.
        return head->data;
    }
}

string queue::removeFront() {
    string poppedData;
    if (queueEmpty() == true) {
        cout << "Queue is empty. Cannot pop front.";
    }
    else { // Store the data on a variable, create a temp node, move the head, and delete the temp node.
        poppedData = head->data;
        Node* temp = head;
        head = head->next;
        delete temp;
        queuesize--;

        return poppedData;
    }
}

bool queue::queueEmpty() {
    return queuesize < 1;
}

int queue::queueSize() {
    return queuesize;
}

queue::queue() {
    head = nullptr;
    tail = nullptr;
    queuesize = 0;
}