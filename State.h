#ifndef STATE_H
#define STATE_H

#include <iostream>
#include <vector>

using namespace std;

class State {
    private:
        vector<int> holds_puzzle; // empty vector


    public:
        State(vector<int> initialPuzzle) : holds_puzzle(initialPuzzle) {}
        
        // returns true if the current puzzle is the goal state
        bool isGoalState() const {
            const vector<int> goal_state = {1, 2, 3, 4, 5, 6, 7, 8, 0};
            return holds_puzzle == goal_state;
        }

        // possible nodes generated from current node
        vector<State> getChildren() const {
            vector<State> successors;
            int blank_tile = getBlankTile(); // returns the position or index of the blank tile
            int row = blank_tile / 3; 
            int col = blank_tile % 3;

            int row_actions[] = {-1, 1, 0, 0}; // up, down
            int col_actions[] = {0, 0, -1, 1}; // left, right

            for (int i = 0; i < 4; ++i) {
                int row_b = row + row_actions[i];
                int col_b = col + col_actions[i];
                if (row_b >= 0 && row_b < 3 && col_b >=0 && col_b < 3) {
                    int newIndex = row_b * 3 + col_b;
                    vector<int> temp_puzzle = holds_puzzle;
                    swap(temp_puzzle[blank_tile], temp_puzzle[newIndex]);
                    successors.push_back(State(temp_puzzle));
                }
            }
            return successors;
        }

        // Equality operator allows comparison between states
        bool operator==(const State& other) const {
            return holds_puzzle == other.holds_puzzle;
        }
        bool operator<(const State& other) const {
            return holds_puzzle < other.holds_puzzle;
        }

        // finds an empty tile
        size_t getBlankTile() const {
            return find(holds_puzzle.begin(), holds_puzzle.end(), 0) - holds_puzzle.begin();
        }

        const vector<int>& getHoldsPuzzle() const{
            return holds_puzzle;
        }

        void print() const {
            for (size_t i = 0; i < holds_puzzle.size(); ++i) {
                if (i % 3 == 0) 
                    cout << endl;
                if (holds_puzzle[i] == 0)
                    cout << "b ";
                else
                    cout << holds_puzzle[i] << " ";
            }
        cout << endl;
    }
};

#endif