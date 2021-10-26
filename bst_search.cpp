#include <iostream>

using namespace std;

struct Node {
  int data;
  struct Node *left, *right;
    Node (int data)
  {
    this->data = data;
    left = right = NULL;
  }
};

Node * search (Node * t, int k)
{
  if (t->data == k)
    {
      return t;
    }

  if (k < t->data)
    {
      return search (t->left, k);
    }
  else
    {
      return search (t->right, k);
    }
}

int main ()
{
  struct Node *root = new Node (7);
  root->left = new Node (5);
  root->right = new Node (10);
  root->left->left = new Node (4);
  root->left->right = new Node (6);
  root->right->right = new Node (12);

  struct Node *found = search (root, 5);

  return 0;
}
