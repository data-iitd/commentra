#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to process the list x
int calc(vector<int>& x) {
    // Nested function for further processing
    auto sub = [](vector<int>& y, bool debug = false) {
        // Print the current state of y if debug mode is on
        if (debug) {
            cout << "D ";
            for (int val : y) cout << val << " ";
            cout << endl;
        }
        // Reduce y by repeatedly taking triplets, sorting them, and keeping the middle element
        while (y.size() > 1) {
            vector<int> new_y;
            for (size_t i = 0; i < y.size() - 2; ++i) {
                vector<int> triplet = {y[i], y[i + 1], y[i + 2]};
                sort(triplet.begin(), triplet.end());
                new_y.push_back(triplet[1]);
            }
            y = new_y;
            // Print the current state of y if debug mode is on
            if (debug) {
                cout << "D ";
                for (int val : y) cout << val << " ";
                cout << endl;
            }
        }
        // Return the final single element of y
        return y[0];
    };

    // Process the input list x using sub function
    int y = sub(x);
    // Check if the final element of y is 2
    if (y == 2) {
        sub(x, true);
        cout << "= ";
        for (int val : x) cout << val << " ";
        cout << endl;
    }
    // Return the first element of the final y
    return y;
}

int main() {
    // Read N and X from input
    int N, X;
    cin >> N >> X;

    // Check if X is 1 or N * 2 - 1, print "No" if true
    if (X == 1 || X == N * 2 - 1) {
        cout << "No" << endl;
    } else {
        // Print "Yes" if X is not 1 or N * 2 - 1
        cout << "Yes" << endl;
        // Construct the list xs based on the value of X
        vector<int> xs;
        if (X == N * 2 - 2) {
            for (int i = N - 1; i <= X + 1; ++i) xs.push_back(i);
            for (int i = 1; i < N - 1; ++i) xs.push_back(i);
        } else {
            vector<int> ys;
            for (int i = 1; i < X - 1; ++i) ys.push_back(i);
            for (int i = X + 3; i < N * 2; ++i) ys.push_back(i);
            xs.insert(xs.end(), ys.begin(), ys.begin() + N - 3);
            xs.push_back(X + 2);
            xs.push_back(X - 1);
            xs.push_back(X);
            xs.push_back(X + 1);
            xs.insert(xs.end(), ys.begin() + N - 3, ys.end());
        }
        // Print each element of xs
        for (int x : xs) {
            cout << x << endl;
        }
    }

    return 0;
}

// <END-OF-CODE>
