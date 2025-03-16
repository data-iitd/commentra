#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to perform calculations on the input vector
int calc(vector<int>& x) {
    // Define a helper function to process the vector y
    auto sub = [](vector<int>& y, bool debug = false) {
        // If debug mode is on, print the current state of y
        if (debug) {
            cout << "D ";
            for (int val : y) cout << val << " ";
            cout << endl;
        }
        // Reduce the vector y until it has only one element
        while (y.size() > 1) {
            vector<int> new_y;
            for (size_t i = 0; i < y.size() - 2; ++i) {
                vector<int> temp = {y[i], y[i + 1], y[i + 2]};
                sort(temp.begin(), temp.end());
                new_y.push_back(temp[1]); // Second largest
            }
            y = new_y;
            // If debug mode is on, print the current state of y
            if (debug) {
                cout << "D ";
                for (int val : y) cout << val << " ";
                cout << endl;
            }
        }
        return y[0];
    };

    // Call the helper function to process x
    vector<int> y = x;
    int result = sub(y);

    // If the final result is 2, perform additional processing
    if (result == 2) {
        // Placeholder for potential future logic
        sub(x, true); // Call sub with debug mode on
        cout << "= ";
        for (int val : x) cout << val << " ";
        cout << endl; // Print the original vector x
    }

    // Return the final processed value
    return result;
}

int main() {
    // Read input values N and X from the user
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
            for (int i = N - 1; i <= X + 1; ++i) xs.push_back(i);
            for (int i = 1; i < N - 1; ++i) xs.push_back(i);
            for (int val : xs) cout << val << endl;
        } else {
            // Create a vector ys with specific ranges and then construct xs
            vector<int> ys;
            for (int i = 1; i < X - 1; ++i) ys.push_back(i);
            for (int i = X + 3; i < N * 2; ++i) ys.push_back(i);
            vector<int> xs(ys.begin(), ys.begin() + (N - 3));
            xs.push_back(X + 2);
            xs.push_back(X - 1);
            xs.push_back(X);
            xs.push_back(X + 1);
            xs.insert(xs.end(), ys.begin() + (N - 3), ys.end());

            // Print each element in the final vector xs
            for (int val : xs) cout << val << endl;
        }
    }

    return 0;
}

// <END-OF-CODE>
