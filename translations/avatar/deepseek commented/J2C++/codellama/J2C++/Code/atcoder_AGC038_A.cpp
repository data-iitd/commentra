#include <iostream> // Including iostream for input and output operations
#include <cmath> // Including cmath for mathematical operations

using namespace std; // Using standard namespace

int main() { // Main function is the entry point of the program
    int H, W, A, B; // Declaring variables for the matrix dimensions and the values of A and B

    cin >> H >> W >> A >> B; // Reading the matrix dimensions and the values of A and B

    // Checking if the matrix dimensions are suitable for the given values of A and B
    if (W < 2 * A || H < 2 * B) {
        cout << -1 << endl; // Printing -1 if the matrix dimensions are not suitable
        return 0; // Exiting the program
    }

    // Nested loops to generate the matrix
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            // Assigning 0 or 1 based on the conditions specified
            if ((i < B && j < A) || (i >= B) && (j >= A)) {
                cout << 0; // Writing 0 to the console
            } else {
                cout << 1; // Writing 1 to the console
            }
        }
        cout << endl; // Moving to the next line after each row is written
    }

    return 0; // Exiting the program
}

