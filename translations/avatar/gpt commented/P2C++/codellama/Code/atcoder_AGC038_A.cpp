#include <iostream>
#include <vector>

using namespace std;

void solve(int H, int W, int A, int B) {
    // Initialize a 2D vector (matrix) with dimensions H x W filled with "0"
    vector<vector<char>> answer(H, vector<char>(W, '0'));
    
    // Fill the matrix based on the conditions involving A and B
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            // If we are in the first B rows
            if (i < B) {
                // If we are in the first A columns
                if (j < A) {
                    answer[i][j] = '0';  // Set to "0"
                } else {
                    answer[i][j] = '1';  // Set to "1" for columns >= A
                }
            } else {
                // If we are in rows >= B
                if (j < A) {
                    answer[i][j] = '1';  // Set to "1" for columns < A
                } else {
                    answer[i][j] = '0';  // Set to "0" for columns >= A
                }
            }
        }
    }
    
    // Print the resulting matrix row by row
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cout << answer[i][j];
        }
        cout << endl;
    }
    
    return;
}

int main() {
    // Generator function to iterate over input tokens
    auto iterate_tokens = [](istream& in) {
        string line;
        while (getline(in, line)) {
            istringstream iss(line);
            for (string word; iss >> word; ) {
                yield word;
            }
        }
    };
    
    // Read input values for H, W, A, and B
    auto tokens = iterate_tokens(cin);
    int H = stoi(next(tokens));  // Height of the matrix
    int W = stoi(next(tokens));  // Width of the matrix
    int A = stoi(next(tokens));  // Column threshold for "0" and "1"
    int B = stoi(next(tokens));  // Row threshold for "0" and "1"

    // Call the solve function with the input parameters
    solve(H, W, A, B);

    return 0;
}

// END-OF-CODE
