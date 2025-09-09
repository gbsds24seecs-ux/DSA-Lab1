#include <iostream>
using namespace std;

// function to generate  triangle up to n rows
void generatePascal(int n) {
    // If n is 0, no triangle to generate
    if (n <= 0) {
        cout << "Empty triangle\n";
        return;
    }

    // Create a 2D array to store Pascal's triangle
    int triangle[100][100]; // A simple fixed-size array (max 100 rows)

    // Loop through each row
    for (int i = 0; i < n; ++i) {
        // Loop through each element in the row
        for (int j = 0; j <= i; ++j) {
            // Set the first and last elements of each row to 1
            if (j == 0 || j == i) {
                triangle[i][j] = 1;
            } else {
                // Set the inner elements to the sum of the two elements above it
                triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }
        }
    }

    // Print the triangle
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            cout << triangle[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    // Test cases

    // Test n = 0 (empty triangle)
    cout << "Test n = 0:\n";
    generatePascal(0);  // Empty triangle
    cout << endl;

    // Test n = 1
    cout << "Test n = 1:\n";
    generatePascal(1);  // Single row: 1
    cout << endl;

    // Test n = 5
    cout << "Test n = 5:\n";
    generatePascal(5);  // Print first 5 rows of Pascal's triangle
    cout << endl;

    return 0;
}