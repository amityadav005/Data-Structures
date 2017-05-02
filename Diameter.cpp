#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* left, *right;
};
int max(int a, int b)
{
    return (a >= b)? a: b;
}
struct node* newNode(int data)
{
    struct node* node = (struct node*)
            malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return(node);
}
int height(struct node* node)
{
    /* base case tree is empty */
    if(node == NULL)
        return 0;

    /* If tree is not empty then height = 1 + max of left
       height and right heights */
    return 1 + max(height(node->left), height(node->right));
}
void printr(node* root){
    if(root==NULL)
        return;
    printf("%d ", root->data);
    int  lh = height(root->left);
    int rh = height(root->right);
    if(lh>=rh)
        printr(root->left);
    else
        printr(root->right);



}
void print(node*root){
    if(root==NULL)
        return;
    printf("%d ", root->data);
    printr(root->left);
    printr(root->right);
}
int diameter(struct node *root, int* height, node* *node)
{
/* lh --> Height of left subtree
	rh --> Height of right subtree */
    int lh = 0, rh = 0;

/* ldiameter --> diameter of left subtree
	rdiameter --> Diameter of right subtree */
    int ldiameter = 0, rdiameter = 0;

    if(root ==NULL)
    {
        *height = 0;
        return 0; /* diameter is also 0 */
    }

/* Get the heights of left and right subtrees in lh and rh
	And store the returned values in ldiameter and ldiameter */
    ldiameter = diameter(root->left, &lh,node);
    rdiameter = diameter(root->right, &rh,node);

/* Height of current node is max of heights of left and
	right subtrees plus 1*/
    *height = max(lh, rh) + 1;
    if(((lh + rh + 1)>=ldiameter)&&((lh + rh + 1)>=rdiameter))
        *node = root;
    else if((ldiameter>=(lh + rh + 1))&&(ldiameter>= rdiameter))
        *node = root->left;
    else if((rdiameter>=(lh + rh + 1))&&(rdiameter>= ldiameter))
        *node = root->right;
    return max(lh + rh + 1, max(ldiameter, rdiameter));
}
int main()
{

    /* Constructed binary tree is
              1
            /   \
          2      3
        /  \
      4     5
    */
    struct node *root = newNode(1);
    root->left        = newNode(2);
    //root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
    root->left->left->left  = newNode(6);
    //root->left->left->left->left  = newNode(16);
    root->left->right->right = newNode(7);
    root->left->right->right->right = newNode(8);
    int h=0;
    node* r;
    printf("Diameter of the given binary tree is %d\n", diameter(root,&h,&r));
    //printf("%d", r->data);

    print(r);

    return 0;
}
