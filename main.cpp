#include <iostream>
#include <vector>
#include <limits>
#include <sstream>

using namespace std;

int main()
{
    cout << "Welcome to XXX (change this to your student ID) 8 puzzle solver.\n";
    cout << "Type \"1\" to use a default puzzle, or \"2\" to enter your own puzzle.\n";
    int option;
    
    while (true) {
        if (cin >> option && (option == 1 || option == 2)) {
            break; // skip to next code if user inputs 1 or 2
        } else {
            cout << "Invalid input. Please try again: ";
            cin.clear(); // 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the newline character from the input buffer
        }
    }
    
    vector<vector<int>> puzzle(3, vector<int>(3)); // creates a 2D vector for a 3x3 matrix
    // {{0,0,0}, {0,0,0}, {0,0,0}}

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
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (int i = 0; i < 3; ++i) {
            string order;
            switch(i) {
                case 0:
                    order = "first";
                    break;
                case 1:
                    order = "second";
                    break;
                case 2:
                    order = "third";
                    break;
                default:
                    order = "";
            }

            cout << "Enter the " << order << " row, use space or tabs between numbers ";
 
            string line;
            while (true) {
                getline(cin, line); // reads user input
                istringstream iss(line); // iss has contents of line
                int num;
                vector<int> row;

                while (iss >> num) { 
                    row.push_back(num); // each user input is pushed inside vector row
                }

                if (row.size() == 3) { // checks if user input exactly 3 numbers
                    puzzle[i] = row; // row vector is put in ith row of puzzle 
                    break;
                } else {
                    cout << "Invalid input. Please enter exactly three numbers separated by spaces: ";
                }
            }
        }
    }
    
    // Display the maxtrix
    for (const auto& row : puzzle) {
        for (int num : row) {
            if(num == 0)
                cout << "b ";
            else
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