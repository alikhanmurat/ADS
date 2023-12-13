#include <iostream>
#define ll long long int
using namespace std;

struct Node {
    int value;
    Node* next;


};

Node* head = nullptr;  

void insert(int x) {
    Node* newNode = new Node;
    newNode->value = x;
    newNode->next = nullptr;
    if (!head) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void findnearest(int y) {
    int nearestposition = 0, currentposition = 1, distance1 = abs(head->value - y);
    Node* current = head->next;

    while (current) {
        int distance2 = abs(current->value - y);
        if (distance2 < distance1) {
            distance1 = distance2;
            nearestposition = currentposition;
        }

        current = current->next;
        currentposition++;
    }

    cout << nearestposition;
}

int main() {
    int x;
    cin >> x;

    for (int i = 0; i < x; i++) {
        int y;
        cin >> y;
        insert(y);
    }

    int z;
    cin >> z;

    findnearest(z);

    return 0;
}