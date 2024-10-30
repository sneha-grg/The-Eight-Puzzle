#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>
#include <cmath>



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



int calculate_heuristic(const vector<vector<int>>& state, const vector<vector<int>>& goal) {
  int heuristic = 0; 
  unordered_map <int, pair<int,int>> goal_tmp;
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      goal_tmp[goal[i][j]] = {i, j};
      // records the index value of every number in goal state
      // {3, (0,2)}
    }
  }

  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      if ((goal[i][j] != state[i][j]) && (state[i][j] != 0)) {
        pair<int, int> position = goal_tmp[state[i][j]];
        int row = position.first;
        int col = position.second;
        heuristic += (abs(i - row) + abs(j - col));
      }
    }
  }

  return heuristic;
}
















