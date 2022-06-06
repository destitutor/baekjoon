#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int index;
    int x;
    int y;
    Node* left;
    Node* right;
};

void preorder(Node* root, vector<int>& answer) {
    if (root == NULL) return;
    answer.push_back(root->index);
    preorder(root->left, answer);
    preorder(root->right, answer);
}

void postorder(Node* root, vector<int>& answer) {
    if (root == NULL) return;
    postorder(root->left, answer);
    postorder(root->right, answer);
    answer.push_back(root->index);
}

void createBinaryTree(Node* root, Node* child) {
    if (root->x > child->x) {
        if (root->left == NULL) {
            root->left = child;
            return;
        }
        createBinaryTree(root->left, child);
    } else {
        if (root->right == NULL) {
            root->right = child;
            return;
        }
        createBinaryTree(root->right, child);
    }
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<Node> tree;
    
    for (int i = 0; i < nodeinfo.size(); i++)
        tree.push_back({ i+1, nodeinfo[i][0], nodeinfo[i][1], NULL, NULL });
    sort(tree.begin(), tree.end(), [](Node& n1, Node& n2) {
        if (n1.y == n2.y)
            return n1.x < n2.x;
        return n1.y > n2.y;
    });
    
    Node* root = &tree[0];
    for (int i = 1; i < tree.size(); i++)
        createBinaryTree(root, &tree[i]);
    
    vector<int> preorders;
    vector<int> postorders;
    preorder(root, preorders);
    postorder(root, postorders);
    return { preorders, postorders };
}