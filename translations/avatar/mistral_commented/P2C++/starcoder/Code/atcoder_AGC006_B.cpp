#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {
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
            vector<int> xs(N-1, 0);
            copy(range(1, N-1), back_inserter(xs));
            copy(range(N-1, X+2), back_inserter(xs));
        } else {
            vector<int> ys(N*2, 0);
            copy(range(1, X-1), back_inserter(ys));
            copy(range(X+3, N*2), back_inserter(ys));
            vector<int> xs(ys.begin(), ys.begin() + N-3);
            xs.push_back(X+2);
            xs.push_back(X-1);
            xs.push_back(X);
            xs.push_back(X+1);
            copy(ys.begin() + N-3, ys.end(), back_inserter(xs));
        }
        // Calculate the list xs based on the value of X

        copy(xs.begin(), xs.end(), ostream_iterator<int>(cout, " "));
        cout << endl;
        // Print each element of the list xs
    }
    // Return 0 to the operating system
}
// End of code

