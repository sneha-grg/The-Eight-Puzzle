#include <iostream>
using namespace std;

class Tree
{
  private:

  public:
};

struct Node
{
    Tree t;
    Node* parent;
    Node* next;
    Node* left;
    Node* right;
};

// Function to create a new Node
Node* new_node(Tree new_leaf, Node* parent)
{
  Node* n = new Node;
  n->t = new_leaf; 
  n->parent = parent;
  n->left = NULL;
  n->right = NULL;
  n->next = NULL;
  return n;
}
