

#include <iostream> // Including the necessary libraries for input/output operations
#include <vector> // Including the necessary library for vector data structure

using namespace std; // Using the standard namespace for input/output operations

int main() {
    int n, k, l, r, sAll, sk; // Declaring the input variables n, k, l, r, sAll, and sk

    cin >> n >> k >> l >> r >> sAll >> sk; // Reading the input values from the user

    vector<int> ans(n, l); // Initializing a vector ans of size n to store the updated scores of all points

    sAll -= sk + (n - k) * l; // Calculating the remaining score after removing the given k points and segments of length l

    sk -= k * l; // Calculating the remaining score after removing the given k points

    int idx = n - 1; // Declaring the variable idx to store the index of the current point

    while (sk > 0 && idx >= n - k) { // Executing the first while loop to increase the score of the given k points
        ans[idx--]++; // Increasing the score of the current point by 1
        sk--; // Decreasing the remaining score by 1
    }

    while (sAll > 0) { // Executing the second while loop to increase the score of the remaining points
        idx = 0; // Resetting the index idx to 0 for the next iteration of the loop
        while (sAll > 0 && idx < n - k) { // Executing the inner while loop to increase the score of the remaining points
            ans[idx++]++; // Increasing the score of the current point by 1
            sAll--; // Decreasing the remaining score by 1
        }
    }

    for (int i = 0; i < n; i++) { // Printing the updated scores of all points
        cout << ans[i] << " "; // Printing each updated score followed by a space
    }

    cout << endl; // Printing a newline after printing all scores

    return 0; // Returning 0 to indicate successful execution of the program
}

These comments should provide a clear understanding of the code and its logical flow.