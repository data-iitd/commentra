
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Define a function to perform calculations on the input vector
int calc(vector<int> x) {
    // Define a helper function to process the vector y
    vector<int> sub(vector<int> y, int debug = 0) {
        // If debug mode is on, print the current state of y
        if (debug) {
            for (int i = 0; i < y.size(); i++) {
                cout << "D " << y[i] << endl;
            }
        }
        // Reduce the vector y until it has only one element
        while (y.size() > 1) {
            // Replace y with the second largest element of every three consecutive elements
            for (int i = 0; i < y.size() - 2; i++) {
                vector<int> temp = y;
                sort(temp.begin() + i, temp.begin() + i + 3);
                y[i + 1] = temp[i + 1];
            }
            // If debug mode is on, print the current state of y
            if (debug) {
                for (int i = 0; i < y.size(); i++) {
                    cout << "D " << y[i] << endl;
                }
            }
        }
        return y;
    }

    // Call the helper function to process x
    vector<int> y = sub(x);

    // If the final result is 2, perform additional processing
    if (y[0] == 2) {
        sub(x, 1);  // Call sub with debug mode on
        for (int i = 0; i < x.size(); i++) {
            cout << "=" << x[i] << endl;
        }
    }

    // Return the final processed value
    return y[0];
}

int main() {
    int N, X;
    cin >> N >> X;

    // Check specific conditions based on the value of X
    if (X == 1 || X == N * 2 - 1) {
        // If X is at the boundaries, print "No"
        cout << "No" << endl;
    } else {
        // If X is within the valid range, print "Yes"
        cout << "Yes" << endl;

        // Handle the case where X is N * 2 - 2
        if (X == N * 2 - 2) {
            // Create a vector xs with specific ranges
            vector<int> xs;
            for (int i = N - 1; i <= X + 1; i++) {
                xs.push_back(i);
            }
            for (int i = 1; i < N - 1; i++) {
                xs.push_back(i);
            }
        } else {
            // Create a vector ys with specific ranges and then construct xs
            vector<int> ys;
            for (int i = 1; i < X - 1; i++) {
                ys.push_back(i);
            }
            for (int i = X + 3; i < N * 2; i++) {
                ys.push_back(i);
            }
            vector<int> xs;
            for (int i = 0; i < N - 3; i++) {
                xs.push_back(ys[i]);
            }
            xs.push_back(X + 2);
            xs.push_back(X - 1);
            xs.push_back(X);
            xs.push_back(X + 1);
            for (int i = N - 3; i < ys.size(); i++) {
                xs.push_back(ys[i]);
            }
        }

        // Print each element in the final vector xs
        for (int i = 0; i < xs.size(); i++) {
            cout << xs[i] << endl;
        }
    }

    return 0;
}
