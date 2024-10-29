#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int main()
{
    cout << "Welcome to XXX (change this to your student ID) 8 puzzle solver.\n";
    cout << "Type \"1\" to use a default puzzle, or \"2\" to enter your own puzzle.\n";
    int option;
    
    while (true) {
        if (cin >> option && (option == 1 || option == 2)) {
            break;
        } else {
            cout << "Invalid input. Please try again: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
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

    int choice;
    while (true) {
        if (cin >> choice && (choice >= 1 && choice <= 3)) {
            break;
        } else {
            cout << "Invalid input. Please enter 1, 2, or 3: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    cout << "Algorithm choice: ";
    if (choice == 1) {
        cout << "Uniform Cost Search" << endl; // ADD UNIFORM COST OBJECT HERE
    } else if (choice == 2) {
        cout << "A* with the Misplaced Tile heuristic." << endl; // ADD MISPLACED TILE OBJECT HERE
    } else if (choice == 3) {
        cout << "A* with the Euclidean distance heuristic." << endl; // ADD EUCLIDEAN DISTANCE HERE
    }

    cout << "That's all folks!" << endl;
    
    return 0;
}