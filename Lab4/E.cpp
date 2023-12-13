#include <bits/stdc++.h>
#define ll long long int
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

void insert(vector <Node*> &nodes, int y, int z, int w) {
    Node* newNode = new Node(y);
    nodes[z] = newNode;

    if (w == 0) {
        nodes[y]->left = newNode;
    } else {
        nodes[y]->right = newNode;
    }
}

int width(Node* root) {
    if (root == nullptr)
        return 0;

    queue<Node*> q;
    q.push(root);
    int maxWidth = 0;

    while (!q.empty()) {
        int cnt = q.size();
        maxWidth = max(maxWidth, cnt);

        while (cnt--) {
            Node* node = q.front();
            q.pop();

            if (node->left)
                q.push(node->left);

            if (node->right)
                q.push(node->right);
        }
    }

    return maxWidth;
}

int main() {
    int x;
    cin >> x;

    vector <Node*> nodes(x + 1, nullptr);

    for (int i = 1; i < x; i++) {
        int y, z, w;
        cin >> y >> z >> w;
        if (nodes[y] == nullptr)
            nodes[y] = new Node(y);

        insert(nodes, y, z, w);
    }

    int maxWidth = width(nodes[1]);
    cout << maxWidth << endl;

    return 0;
}