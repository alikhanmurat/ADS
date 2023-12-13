#include <bits/stdc++.h>
#define ll long long int
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

Node* insert(Node* node, int z) {
    if (node == nullptr) {
        return new Node(z);
    }

    if (z < node->value) {
        node->left = insert(node->left, z);
    } else {
        node->right = insert(node->right, z);
    }

    return node;
}

int vertice(Node* node) {
    if (!node) {
        return 0;
    }

    int cnt = 0;
    cnt += vertice(node->left);
    cnt += vertice(node->right);

    if (node->left != nullptr && node->right != nullptr) {
        cnt++;
    }

    return cnt;
}

int main() {
    int x;
    cin >> x;

    Node* root = nullptr;

    for (int i = 0; i < x; i++) {
        int z;
        cin >> z;
        root = insert(root, z);
	}
    int num = vertice(root);
	cout << num;
    return 0;
}
