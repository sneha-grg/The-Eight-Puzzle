#include <iostream>
#include <vector>
#include <limits>
#include "Tree.h"

using namespace std;

int main()
{

    vector<vector<int>> goal = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 0}
    };
    
    cout << "Welcome to XXX (change this to your student ID) 8 puzzle solver.\n";
    cout << "Type \"1\" to use a default puzzle, or \"2\" to enter your own puzzle.\n";
    int option;
    
    while (true) {
        if (cin >> option && (option == 1 || option == 2)) {
            break; // Valid input received
        } else {
            cout << "Invalid input. Please try again: ";
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        }
    }
    
    vector<vector<int>> puzzle(3, vector<int>(3));

    if(option == 1) {
        puzzle = {
            {1, 2, 3},
            {4, 0, 6},
            {7, 5, 8}
        };

        cout << "Using default puzzle:\n";
    }
    else if (option == 2) {
        cout << "Enter your puzzle, use a zero to represent the blank\n";
    }
    
    // Display the maxtrix
    for (const auto& row : puzzle) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    // Prompt for algorithm choice
    cout << "Enter your choice of algorithm\n";
    cout << "1. Uniform Cost Search\n";
    cout << "2. A* with the Misplaced Tile heuristic.\n";
    cout << "3. A* with the Euclidean distance heuristic.\n";


    vector<vector<int>> start = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 0, 8}
    };

    vector<vector<int>> goal = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 0}
    };



    
    return 0;
}