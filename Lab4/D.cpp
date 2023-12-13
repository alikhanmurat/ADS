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

int treeHeight(Node* node){
	if (node == NULL)
        return 0;

    int leftHeight = treeHeight(node->left);
    int rightHeight = treeHeight(node->right);

    return max(leftHeight, rightHeight) + 1;

}

void levelSum (Node* node){
	if (node == nullptr)
        return;

    queue<Node*> q;
    q.push(node);
    q.push(nullptr); 

    int sum = 0;

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        if (current != nullptr) {
            sum += current->value;

            if (current->left)
                q.push(current->left);

            if (current->right)
                q.push(current->right);
        } else {
            cout  << sum << ' ';
            sum = 0;

            if (!q.empty())
                q.push(nullptr);

        }
    }
}

int main() {
    int x, y;
    cin >> x;

    Node* root = nullptr;

    for (int i = 0; i < x; i++) {
        int z;
        cin >> z;
        root = insert(root, z);
    }
    
    int height = treeHeight(root);
    cout << height << endl;
	levelSum(root);
    return 0;
}