#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Define a function named 'solve' that takes four integer arguments: H, W, A, and B.
void solve(int H, int W, int A, int B) {
    // Initialize a 2D vector named 'answer' of size H x W with all elements set to the string "0".
    vector<vector<string>> answer(H, vector<string>(W, "0"));

    // Iterate through each row 'i' in the range of H.
    for (int i = 0; i < H; ++i) {
        // Iterate through each column 'j' in the range of W.
        for (int j = 0; j < W; ++j) {
            // Set the value of the cell 'answer[i][j]' based on the conditions.
            if (i < B) {
                if (j < A) {
                    answer[i][j] = "0";
                } else {
                    answer[i][j] = "1";
                }
            } else {
                if (j < A) {
                    answer[i][j] = "1";
                } else {
                    answer[i][j] = "0";
                }
            }
        }
    }

    // Iterate through each row 'i' in the range of H and print its elements joined by an empty string.
    for (int i = 0; i < H; ++i) {
        cout << string(answer[i].begin(), answer[i].end()) << endl;
    }
}

// Define a function named 'main' that does not take any arguments.
int main() {
    int H, W, A, B;

    // Read the input values for H, W, A, and B.
    cin >> H >> W >> A >> B;

    // Call the 'solve' function with the given input.
    solve(H, W, A, B);

    return 0;
}

// <END-OF-CODE>
