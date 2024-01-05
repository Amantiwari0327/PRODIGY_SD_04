#include <bits/stdc++.h>
using namespace std;

const int N = 9;

// Function to check if a number can be placed at a given position
bool isSafe(int grid[N][N], int row, int col, int num) {
    // Check if the number is already present in the row or column
    for (int i = 0; i < N; ++i) {
        if (grid[row][i] == num || grid[i][col] == num) {
            return false;
        }
    }

    // Check if the number is already present in the 3x3 grid
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (grid[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }

    return true;
}

// Function to solve the Sudoku puzzle using backtracking
bool solveSudoku(int grid[N][N]) {
    int row, col;

    // Check if there is any unassigned location
    bool found = false;
    for (row = 0; row < N; ++row) {
        for (col = 0; col < N; ++col) {
            if (grid[row][col] == 0) {
                found = true;
                break;
            }
        }
        if (found) {
            break;
        }
    }

    // If no unassigned location is found, puzzle is solved
    if (!found) {
        return true;
    }

    // Try placing numbers 1 to 9 at the current position
    for (int num = 1; num <= 9; ++num) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;

            // Recursively solve the rest of the puzzle
            if (solveSudoku(grid)) {
                return true;
            }

            // If placing num at current position doesn't lead to a solution, backtrack
            grid[row][col] = 0;
        }
    }

    // If no number can be placed at the current position, backtrack
    return false;
}

// Function to display the solved Sudoku grid
void displayGrid(int grid[N][N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    // Input unsolved Sudoku grid
    int grid[9][9];
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cin>>grid[i][j];
        }
    }

    if (solveSudoku(grid)) {
        cout << "Sudoku solved successfully:\n";
        displayGrid(grid);
    } else {
        cout << "No solution exists for the given Sudoku puzzle\n";
    }

    return 0;
}
