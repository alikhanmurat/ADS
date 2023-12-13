#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int sum = 0;
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

void lineSum(Node* node){
        if(!node){
			return;
		}
        lineSum(node->right);
        sum += node->value;
        cout<<sum<<" ";
        lineSum(node->left);
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
	lineSum(root);
    return 0;
}
