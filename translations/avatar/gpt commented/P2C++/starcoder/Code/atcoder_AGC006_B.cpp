#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Read input values N and X from the user
    int N, X;
    cin >> N >> X;
    
    // Define a function to perform calculations on the input list
    int calc(vector<int> x) {
        // Define a helper function to process the list y
        int sub(vector<int> y, bool debug = false) {
            // If debug mode is on, print the current state of y
            if (debug) {
                for (int i = 0; i < y.size(); i++) {
                    cout << "D" << y[i] << " ";
                }
                cout << endl;
            }
            // Reduce the list y until it has only one element
            while (y.size() > 1) {
                // Replace y with the second largest element of every three consecutive elements
                for (int i = 0; i < y.size() - 2; i++) {
                    y[i] = max(y[i], y[i + 1]);
                }
                // If debug mode is on, print the current state of y
                if (debug) {
                    for (int i = 0; i < y.size(); i++) {
                        cout << "D" << y[i] << " ";
                    }
                    cout << endl;
                }
            }
            return y[0];
        }
        
        // Call the helper function to process x
        int y = sub(x);
        
        // If the final result is 2, perform additional processing
        if (y == 2) {
            // Placeholder for potential future logic
            sub(x, true);  // Call sub with debug mode on
            for (int i = 0; i < x.size(); i++) {
                cout << x[i] << " ";
            }
            cout << endl;
        }
        
        // Return the final processed value
        return y;
    }
    
    // Check specific conditions based on the value of X
    if (X == 1 || X == N * 2 - 1) {
        // If X is at the boundaries, print "No"
        cout << "No" << endl;
    } else {
        // If X is within the valid range, print "Yes"
        cout << "Yes" << endl;
        
        // Handle the case where X is N * 2 - 2
        if (X == N * 2 - 2) {
            // Create a list xs with specific ranges
            vector<int> xs;
            for (int i = N - 1; i <= X + 2; i++) {
                xs.push_back(i);
            }
            for (int i = 1; i <= N - 1; i++) {
                xs.push_back(i);
            }
        } else {
            // Create a list ys with specific ranges and then construct xs
            vector<int> ys;
            for (int i = 1; i <= X - 1; i++) {
                ys.push_back(i);
            }
            for (int i = X + 3; i <= N * 2; i++) {
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
        
        // Print each element in the final list xs
        for (int i = 0; i < xs.size(); i++) {
            cout << xs[i] << endl;
        }
    }
    
    // Return 0 to indicate successful execution
    return 0;
}

