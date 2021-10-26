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

int
main ()
{
  struct Node *root = new Node (7);
  root->left = new Node (5);
  root->right = new Node (10);
  root->left->left = new Node (4);
  root->left->right = new Node (6);
  root->right->right = new Node (12);

  root = insert (root, 13);

  printInorder (root);

  return 0;
}
