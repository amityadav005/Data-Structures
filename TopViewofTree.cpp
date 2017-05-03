#include <iostream>
#include <cstdlib>
#include <queue>

using namespace std;
struct Node {
    int data;
    Node *left;
    Node *right;
     int hd;
};


Node *newNode(int data) {
    Node *temp = (Node *) malloc(sizeof(Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    temp->hd = 0;
    return temp;
}

void inorder(Node *root) {
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void top_view(Node *root, int min, int max) {
    if (root == NULL)
        return;
    queue<Node* >q;
    q.push(root);
    cout<<root->data<<" ";
    while(!q.empty()){
        Node* t = q.front();
        q.pop();
        if (t->hd== min) {
            cout << t->data<<" ";
            min = t->hd-1;
        } else if (t->hd == max) {
            cout << t->data<<" ";
            max = t->hd+1;
        }
        if(t->left){
            t->left->hd = t->hd-1;
            q.push(t->left);
        }
        if(t->right){
            t->right->hd = t->hd+1;
            q.push(t->right);
        }
    }


}

int main() {

    Node *root;
    root = newNode(10);
    root->left = newNode(-2);
    root->right = newNode(6);
    // root->left->left = newNode(8);
    root->left->right = newNode(-4);
    root->left->right->right = newNode(11);
    root->left->right->right->right = newNode(13);
    root->left->right->right->right->right = newNode(15);
    root->left->right->left = newNode(22);
    root->left->right->left->left = newNode(44);
    root->left->right->left->left->left = newNode(66);
    root->right->left = newNode(7);
    root->right->right = newNode(5);
    top_view(root, -1,1);

}