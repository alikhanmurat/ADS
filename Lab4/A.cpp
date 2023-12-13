#include <bits/stdc++.h>
#define ll long long int
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

Node* insert(Node* node, int y) {
    if (node == nullptr) {
        return new Node(y);
    }

    if (y < node->value) {
        node->left = insert(node->left, y);
    } else {
        node->right = insert(node->right, y);
    }

    return node;
}

bool isPathAvailable(Node* node, string z, int cnt) {
    if (node == nullptr)
        return false;

    if (cnt == z.length())
        return true;

    if (z[cnt] == 'L')
        return isPathAvailable(node->left, z, cnt + 1);
    else if (z[cnt] == 'R')
        return isPathAvailable(node->right, z, cnt + 1);

    return false;
}



int main() {
    int x, w;
    cin >> x >> w;

    Node* root = nullptr;

    for (int i = 0; i < x; i++) {
        int y;
        cin >> y;
        root = insert(root, y);
    }

    for (int i = 0; i < w; i++) {
        string z;
        cin >> z;
        bool isAvailable = isPathAvailable(root, z, 0);
        if (isAvailable) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
