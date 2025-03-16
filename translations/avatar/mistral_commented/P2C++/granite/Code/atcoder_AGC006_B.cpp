
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> calc(int x) {
// Define a function calc that takes an integer x as an argument

    vector<int> sub(vector<int> y, bool debug = false) {
    // Define a nested function sub that takes a vector<int> y and an optional debug boolean

        if (debug) {
            cout << "D " << y[0] << endl;
        }
    // If debug is true, print the intermediate values of y

        while (y.size() > 1) {
            vector<int> z;
            for (int i = 0; i < y.size() - 2; i++) {
                vector<int> t = {y[i], y[i+1], y[i+2]};
                sort(t.begin(), t.end());
                z.push_back(t[1]);
            }
            y = z;
            if (debug) {
                cout << "D " << y[0] << endl;
            }
        }
    // Sort and select the middle element from sublists of length 3 in y

        return y;
    }
// Return the result of the sub function

    vector<int> y = sub({x}, false);
    // Calculate the result y of the sub function for the given input x

    if (y[0] == 2) {
        sub({x}, true);
        cout << "=" << x << endl;
    }
    // If the first element of y is 2, call the sub function recursively with x-1 and print x

    return {y[0]};
}
// Return the first element of the y vector

int main() {
// Define the main function

    int N, X;
    cin >> N >> X;
    // Read input values N and X from the standard input

    if (X == 1 || X == N * 2 - 1) {
    // Check if X is equal to 1 or N*2-1

        cout << "No" << endl;
    // If it is, print "No"
    } else {
    // Else, X is neither 1 nor N*2-1

        cout << "Yes" << endl;
    // Print "Yes"

        if (X == N * 2 - 2) {
            vector<int> xs(N);
            for (int i = 0; i < N; i++) {
                xs[(i + N - 2) % N] = X + 2 - i;
            }
            // Calculate the list xs based on the value of X
        } else {
            vector<int> ys(N);
            for (int i = 0; i < N; i++) {
                ys[i] = X + 3 - i;
            }
            vector<int> xs(N);
            for (int i = 0; i < N; i++) {
                xs[i] = ys[(i + N - 3) % N];
            }
            xs[N - 3] = X + 2;
            xs[N - 2] = X - 1;
            xs[N - 1] = X;
            // Calculate the list xs based on the value of X
        }

        for (int x : xs) {
            cout << x << endl;
        }
    // Print each element of the list xs
    }

    return 0;
}
// End of the main function

