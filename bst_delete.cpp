#include <iostream>

using namespace std;

struct Node
{
  int data;
  struct Node *left, *right;
    Node (int data)
  {
    this->data = data;
    left = right = NULL;
  }
};


void
printInorder (struct Node *node)
{
  if (node == NULL)
    return;

  /* first recur on left child */
  printInorder (node->left);

  /* then print the data of node */
  cout << node->data << " ";

  /* now recur on right child */
  printInorder (node->right);
}

Node *
insert (Node * t, int d)
{
  if (t == NULL)
    {
      return new Node (d);
    }

  if (d < t->data)
    {
      t->left = insert (t->left, d);
    }
  else
    {
      t->right = insert (t->right, d);
    }

  return t;

}

struct Node* minValueNode(struct Node* node)
{
    struct Node* current = node;
 
    while (current && current->left != NULL)
        current = current->left;
 
    return current;
}

struct Node* deleteNode(struct Node* root, int data)
{
    // base case
    if (root == NULL)
        return root;
 
    if (data < root->data)
        root->left = deleteNode(root->left, data);
 
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
 
    else {
        // node has no child
        if (root->left==NULL and root->right==NULL)
            return NULL;
       
        // node with only one child or no child
        else if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
 
        // (smallest in the right subtree)
        struct Node* temp = minValueNode(root->right);
 
        root->data = temp->data;
 
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}


int main()
{
    struct Node* root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
    
    printInorder(root);
    cout<<endl;
    
    root = deleteNode(root, 20);
    root = deleteNode(root, 30);
    root = deleteNode(root, 50);
    
    printInorder(root);
 

    return 0;
}
