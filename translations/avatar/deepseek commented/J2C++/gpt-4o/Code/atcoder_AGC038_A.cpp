#include <iostream> // Including iostream for input and output
#include <vector> // Including vector for dynamic array handling

using namespace std;

int main() {
    int H, W, A, B; // Declaring variables for height, width, and values A and B
    cin >> H >> W >> A >> B; // Reading the height, width, and values A and B from input

    // Checking if the matrix dimensions are suitable for the given values of A and B
    if (W < 2 * A || H < 2 * B) {
        cout << -1 << endl; // Printing -1 if the matrix dimensions are not suitable
        return 0; // Exiting the program
    }

    // Nested loops to generate the matrix
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            // Assigning 0 or 1 based on the conditions specified
            if ((i < B && j < A) || (i >= B && j >= A)) {
                cout << "0"; // Writing 0 to the output
            } else {
                cout << "1"; // Writing 1 to the output
            }
        }
        cout << endl; // Moving to the next line after each row is written
    }

    return 0; // Indicating that the program ended successfully
}

// <END-OF-CODE>
