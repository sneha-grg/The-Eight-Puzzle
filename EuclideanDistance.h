#ifndef EUCLIDEAN_DISTANCE_H
#define EUCLIDEAN_DISTANCE_H

#include <unordered_map>
#include <vector>
using namespace std;


int calculate_euclidean_heuristic(const vector<vector<int>>& state, const vector<vector<int>>& goal) {
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
            int row = i - position.first;
            int col = j - position.second;
            heuristic += sqrt(row * row + col * col);
        }
        }
    }

    return heuristic;
}

#endif
