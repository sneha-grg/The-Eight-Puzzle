#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>
#include "Node.h"
#include "State.h"

// Comparator for priority queue to order nodes by f(n) = g(n) + h(n)
struct CompareNodes {
    bool operator()(const shared_ptr<Node>& lhs, const shared_ptr<Node>& rhs) const {
        return lhs->getF() > rhs->getF();
    }
};

void ProblemSearch(State initialState, int (*heuristicFunc)(const State&)) {
    int initial_heuristic = heuristicFunc(initialState);
    auto intial_state = make_shared<Node>(initialState, nullptr, 0, initial_heuristic); // g = 0 and h = 0

    // priority queue initialized: ordered by f(n) = g(n) + h(n)
    priority_queue<shared_ptr<Node>, vector<shared_ptr<Node>>, CompareNodes> frontier;
    frontier.push(intial_state);

    // check if a state is in frontier
    set<State> frontierSet;
    frontierSet.insert(initialState);

    // keeps track of expanded states
    set<State> explored_states;

    size_t maxQueueSize = 0;
    int nodes_expanded = 0;

    // runs as long as there are nodes in the frontier
    while (!frontier.empty()) {
        if (frontier.size() > maxQueueSize)
            maxQueueSize = frontier.size(); // queue size is updated if frontier size is greater than queue size

        // retrieves the node with the lowest total cost
        auto current_node = frontier.top();
        frontier.pop();
        frontierSet.erase(current_node->state);

        // checks if current node is the goal state
        if (current_node->state.isGoalState()) {
            cout << "Goal!!!" << endl;
            
            // traces back from goal node to root node using pointer
            vector<shared_ptr<Node>> path;
            auto n = current_node;
            int depth = 0;
            while (n != nullptr) {
                path.push_back(n); // store nodes in vector path
                n = n->parent; // parent pointer
                depth++;
            }

            // reverse the vector so it's path from root to goal nodes
            reverse(path.begin(), path.end());

            // prints the states and solution
            for (auto p : path) {
                cout << "The best state to expand with g(n) = " << p->g
                     << " and h(n) = " << p->h << " is..." << endl;
                p->state.print();
                cout << "Expanding this node..." << endl << endl;
            }
            cout << "To solve this problem the search algorithm expanded a total of "
                 << nodes_expanded << " nodes." << endl;
            cout << "The maximum number of nodes in the queue at any one time: "
                 << maxQueueSize << "." << endl;
            cout << "The depth of the goal node was " << depth - 1 << "." << endl;
            return;
        }
        

        // Add current state to explored_states set
        explored_states.insert(current_node->state);
        // increment counter
        nodes_expanded++;

        // Expand current node and holds and all possible successors from curr state
        vector<State> successors = current_node->state.getChildren();

        for (State child_state : successors) { // iterates through each successor state
            int child_g = current_node->g + 1;
            int child_h = heuristicFunc(child_state);
            // int child_h = 0; // no heuristic calc needed for uniform cost

            // If child_state is not in explored_states set or frontier to avoid revisiting states
            if (explored_states.find(child_state) == explored_states.end() && frontierSet.find(child_state) == frontierSet.end()) {
                auto child_node = make_shared<Node>(child_state, current_node, child_g, child_h);
                frontier.push(child_node);
                frontierSet.insert(child_state);
            }
            else if (frontierSet.find(child_state) != frontierSet.end()) {
            }
        }
    }

    cout << "Failure: No solution found." << endl;
}


