#include <iostream> // Including the iostream library for input and output
#include <vector>   // Including the vector library for dynamic arrays
#include <algorithm> // Including the algorithm library for min function

using namespace std; // Using the standard namespace

class Main { // Defining the Main class
public:
    void solve() { // Method to solve the problem
        int INF = INT_MAX; // Initializing INF with the maximum value of an integer

        int N; // Variable to store the number of elements
        long long X; // Variable to store the value of X
        cin >> N >> X; // Reading the number of elements and the value of X from the console

        vector<long long> x(N); // Creating a vector of size N to store the elements
        vector<long long> xsum(N + 1, 0); // Creating a vector of size N+1 to store the sum of elements up to that index

        for (int i = 0; i < N; i++) { // Loop to read and store the elements in the vector
            cin >> x[i]; // Reading the element
            xsum[i + 1] = xsum[i] + x[i]; // Updating the sum of elements up to the current index
        }

        long long ans = X * N + 5 * xsum[N]; // Initializing the answer with the first calculation

        for (int i = 1; i < N; i++) { // Loop to find the minimum cost
            long long cost = X * i + 5 * (xsum[N] - xsum[N - i]); // Calculating the cost for the current i
            for (int j = 5, k = N - i; k >= 0; j += 2, k -= i) { // Nested loop to check the cost for different j and k
                if (cost > ans) { // If the cost is greater than the current answer, break the loop
                    break;
                }
                cost += j * (xsum[k] - xsum[max(k - i, 0)]); // Updating the cost with the sum of elements between k and k-i
            }
            ans = min(ans, cost); // Updating the answer with the minimum cost found so far
        }

        cout << ans + N * X << endl; // Printing the final answer
    }
};

int main() { // Main method to start the program
    Main().solve(); // Creating an instance of the Main class and calling the solve method
    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
