#include <bits/stdc++.h>
#define ll long long int
using namespace std;

struct Node {
    string word;
    Node* next;
    Node* prev;
};

Node* head = nullptr;
Node* tail = nullptr;
void insert(string x) {
    Node* newNode = new Node();
    newNode->word = x;
    newNode->next = nullptr;
    if (!head) {
        head = tail = newNode;
        return;
    }

    newNode->prev = tail;
    tail->next = newNode;
    tail = newNode;
}

void delete_dup() {
    Node* current1 = head;

    while (current1) {
        Node* current2 = current1->next;

        while (current2 && current1->word == current2->word) {
            Node* duplicate = current2;
            current2 = current2->next;
            if (duplicate == tail) {
                tail = duplicate->prev;
                tail->next = nullptr;
            } else {
                current2->prev = duplicate->prev;
            }
            delete duplicate;
        }

        current1 = current1->next;
    }
}

void print_list() {
    Node* node1 = tail;
    Node* node2 = tail;
    int cnt = 0;

    while (node1) {
        cnt++;
        node1 = node1->prev;
    }

    cout << "All in all: " << cnt << endl;
    cout << "Students: " << endl;

    while (node2) {
        cout << node2->word << endl;
        node2 = node2->prev;
    }
}

int main() {
    ll x;
    cin >> x;

    for (int i = 0; i < x; i++) {
        string y;
        cin >> y;
        insert(y);
    }

    delete_dup();
    print_list();

    return 0;
}