#ifndef EUCLIDEAN_DISTANCE_H
#define EUCLIDEAN_DISTANCE_H

#include <unordered_map>
#include <vector>
using namespace std;


int calculate_euclidean_heuristic(const State& currentState) {
    int heuristic = 0; 
    const vector<vector<int>> goal_state = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 0}
    };

    // add specific indices in goal_temp 
    unordered_map <int, pair<int,int>> goal_tmp;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            goal_tmp[goal_state[i][j]] = {i, j};
            // records the index value of every number in goal state
            // {3, (0,2)}
        }
    }

    // 
    const vector<vector<int>>& curr_puzzle = currentState.getHoldsPuzzle();
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            // if the tile is not where it belongs, it tells you
            if ((goal_state[i][j] != curr_puzzle[i][j]) && (curr_puzzle[i][j] != 0)) {
                pair<int, int> position = goal_tmp[curr_puzzle[i][j]];
                int row = i - position.first;
                int col = j - position.second;
                heuristic += ceil(sqrt(row * row + col * col));
            }
        }
    }

    return heuristic;
}

#endif
