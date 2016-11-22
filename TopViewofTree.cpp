#include <iostream>
#include <cstdlib>
#include <queue>

using namespace std;
struct Node {
    int data;
    Node *left;
    Node *right;
};


Node *newNode(int data) {
    Node *temp = (Node *) malloc(sizeof(Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

void inorder(Node *root) {
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void top_view(Node *root, int min, int max, int level, int k) {
    if (root == NULL)
        return;
    if (k == 1) {
        cout << root->data;
        k = 0;
    } else {

        if (level < min) {
            cout << root->data;
            min = level;
        } else if (level > max) {
            cout << root->data;
            max = level;
        }
    }
    top_view(root->left, min, max, level - 1, k);
    top_view(root->right, min, max, level + 1, k);


}

int main() {

    Node *root;
    root = newNode(10);
    root->left = newNode(-2);
    root->right = newNode(6);
    // root->left->left = newNode(8);
    root->left->right = newNode(-4);
    root->left->right->left = newNode(22);
    root->left->right->left->left = newNode(44);
    root->left->right->left->left->left = newNode(66);
    root->right->left = newNode(7);
    root->right->right = newNode(5);
    top_view(root, 0, 0, 0, 1);

}