#include <iostream>
#include "State.h"
using namespace std;

class Node {
public:
    State state;
    shared_ptr<Node> parent;
    int g;
    int h;

    Node(State state, shared_ptr<Node> parent = nullptr, int g = 0, int h = 0) :
        state(state), parent(parent), g(g), h(h) {}

    int getF() const {
        return g + h;
    }
};

// Comparator for priority queue to order nodes by f(n) = g(n) + h(n)
struct CompareNodes {
    bool operator()(const shared_ptr<Node>& lhs, const shared_ptr<Node>& rhs) const {
        return lhs->getF() > rhs->getF();
    }
};
