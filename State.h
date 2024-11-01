#ifndef STATE_H
#define STATE_H

#include <iostream>
#include <vector>

using namespace std;

class State {
    private:
        vector<vector<int>> holds_puzzle; // empty vector


    public:
        State(vector<vector<int>> initialPuzzle) : holds_puzzle(initialPuzzle) {}
        
        // returns true if the current puzzle is the goal state
        bool isGoalState() const {
            const vector<vector<int>> goal_state = {
                {1, 2, 3},
                {4, 5, 6},
                {7, 8, 0}
            };
            return holds_puzzle == goal_state;
        }

        // possible nodes generated from current node
        vector<State> getChildren() const {
            vector<State> children;
            int row, col;
            
            if (!getBlankTile(row, col))
                return children; // No blank tile found

            int row_actions[] = {-1, 1, 0, 0}; // up, down
            int col_actions[] = {0, 0, -1, 1}; // left, right

            for (int i = 0; i < 4; ++i) {
                int row_b = row + row_actions[i];
                int col_b = col + col_actions[i];
                if (row_b >= 0 && row_b < 3 && col_b >= 0 && col_b < 3) {
                    vector<vector<int>> temp_puzzle = holds_puzzle;
                    swap(temp_puzzle[row][col], temp_puzzle[row_b][col_b]);
                    children.push_back(State(temp_puzzle));
                }
            }
            return children;
        }

        // Equality operator allows comparison between states
        bool operator==(const State& other) const {
            return holds_puzzle == other.holds_puzzle;
        }
        bool operator<(const State& other) const {
            return holds_puzzle < other.holds_puzzle;
        }

        // finds an empty tile
        bool getBlankTile(int& row, int& col) const {
            for (size_t i = 0; i < holds_puzzle.size(); ++i) {
                for (size_t j = 0; j < holds_puzzle[i].size(); ++j) {
                    if (holds_puzzle[i][j] == 0) {
                        row = i;
                        col = j;
                        return true;
                    }
                }
            }
            return false;
        }

        const vector<vector<int>>& getHoldsPuzzle() const {
            return holds_puzzle;
        }

        void print() const {
            for (const auto& row : holds_puzzle) {
                for (int num : row) {
                    if (num == 0)
                        cout << "b ";
                    else
                        cout << num << " ";
                }
                cout << endl;
            }
            cout << endl;
        }
};

#endif