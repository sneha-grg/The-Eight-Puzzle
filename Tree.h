#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>
#include <cmath>
#include <queue>



struct Node
{
  vector <vector<int>> state;
  int g;
  int f;
  int h;
  Node* parent;
  Node(vector <vector<int>> state, int g = 0, int h = 0, Node* parent = nullptr) {
    this->state = state;
    this->parent = parent;
    this->g = g;
    this->h = h;
    this->f = g + h;
  }

  
};

class Comparator {
public:
    bool operator()(const Node* left, const Node* right) const {
        return left->f > right->f; // Min-heap based on f value
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


vector <vector<int>>solve(Node* current, const vector<vector<int>>& goal) {
  priority_queue<Node*, vector<Node*>, Comparator> greatest_f;
  vector<vector<vector<int>>> path_back;
  vector<int> one_dim;
  unordered_map <vector<int>, int> visited;

  while (!greatest_f.empty()) {
    Node* current = greatest_f.top();
    greatest_f.pop();
    cout << "Expanding node with f = " << current->f << endl;

    if (current->state == goal) {
      cout << "Goal reached!" << endl;

      while (current != nullptr) {
        path_back.push_back(current->state); // add the current state
        current = current->parent; // move up to parent
      }

      reverse(path_back.begin(), path_back.end());
      return path_back[0];
      break;
    }

    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        one_dim.push_back(current->state[i][j]);
      }
    }

    if (visited.find(one_dim) != visited.end() && visited[one_dim] <= current->g) {
      continue; // skip if this state has already been visited with a lower g-cost
    }
    visited[one_dim] = current->g;
    one_dim.clear();




  }

}















