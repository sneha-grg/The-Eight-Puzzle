#ifndef MISPLACEDTILEHEURISTIC_H
#define MISPLACEDTILEHEURISTIC_H

#include <vector>
#include "State.h"

using namespace std;

int MisplacedTileHeuristic(const State& currentState) {
    int misplaced = 0;
    const vector<vector<int>> goal_state = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 0}
    };
    const vector<vector<int>>& current_puzzle = currentState.getHoldsPuzzle();
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (current_puzzle[i][j] != 0 && current_puzzle[i][j] != goal_state[i][j]) {
                misplaced++;
            }
        }
    }
    return misplaced;
}

#endif
