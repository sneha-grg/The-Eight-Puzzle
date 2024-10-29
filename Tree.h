#include <iostream>
using namespace std;
#include <vector>



struct Node
{
  vector <vector<int>> state;
  int g;
  int f;
  int h;
  Node* newnode;
  Node(vector <vector<int>> state, int g = 0, int h = 0, Node* newnode = nullptr) {
    this->state = state;
    this->newnode = newnode;
    this->g = g;
    this->h = h;
    this->f = g + h;
  }

  bool operator()(const Node state, const Node other_state ) const {
    return state.f > other_state.f;
  }
};


















