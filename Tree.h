#include <iostream>
using namespace std;
#include <vector>


class Tree;
struct Node
{
  Tree* t; 
  vector <vector<int>> initial;
  int g;
  int f;
  int h;
  Node* parent;
  vector<Node*> children;
  void add_node(Node* child) {
        children.push_back(child);
    }
  Node(vector <vector<int>> init, int g = 0, int h = 0, Node *parent = nullptr, Tree* new_leaf = nullptr) {
    initial = init;
    this->parent = parent;
    this->g = g;
    this->h = h;
    this->f = g + h;
    this->t = new_leaf;
  }


};



class Tree {
  public:
    Node* root;

    Tree(vector<vector<int>> start) {
      root = new Node(start, 0, 0, nullptr, this);
    }

    ~Tree() {
        destroy(root); 
    }

    


  private:
    void destroy(Node* node) {
        if (node != nullptr) {
          for (int i = 0; i < node->children.size(); ++i) {
            destroy(node->children.at(i));
          }
          delete node;
        }
    }
};




