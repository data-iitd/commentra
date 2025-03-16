#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, X;
    cin >> N >> X;
    // Comment: Read input values N and X from the standard input

    vector<int> xs;
    // Comment: Declare a vector xs

    if (X == 1 || X == N * 2 - 1) {
        // Comment: Check if X is equal to 1 or N*2-1

        cout << "No" << endl;
        // Comment: If it is, print "No"

    } else {
        // Comment: Else, X is neither 1 nor N*2-1

        cout << "Yes" << endl;
        // Comment: Print "Yes"

        if (X == N * 2 - 2) {
            for (int i = N - 1; i <= X + 2; i++) {
                xs.push_back(i);
            }
            for (int i = 1; i < N - 1; i++) {
                xs.push_back(i);
            }
        } else {
            vector<int> ys;
            // Comment: Declare a vector ys

            for (int i = 1; i < X - 1; i++) {
                ys.push_back(i);
            }
            for (int i = X + 3; i <= N * 2; i++) {
                ys.push_back(i);
            }
            // Comment: Calculate the vector ys based on the value of X

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
            // Comment: Calculate the vector xs based on the value of X

        }
        // Comment: Print each element of the vector xs

        for (int i = 0; i < xs.size(); i++) {
            cout << xs[i] << endl;
        }

    }

    return 0;
}

