#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Main {
public:
    const int MOD = 1000000007; // Defining a constant value for modulo arithmetic
    const int MAX = INT_MAX; // Defining a constant value for maximum integer
    const long long LMAX = LLONG_MAX; // Defining a constant value for maximum long
    int len = (int)1e6 + 1; // Defining the length of an array

    void doIt() { // Defining the method doIt() to contain the logic of the program
        int N;
        long long K;
        cin >> N >> K; // Reading the number of elements in the array and the long value K
        vector<int> A(N); // Creating an integer vector A of size N

        // Reading the elements of the array A
        for (int i = 0; i < N; i++) {
            cin >> A[i];
            A[i]--; // Subtracting 1 from the input to get the index of the previous element
        }

        unordered_set<int> used; // Creating an unordered_set named used to store the indices that have already been processed
        vector<int> idx(N); // Creating an integer vector named idx to store the position of the current index in the circular array
        vector<int> pos(N); // Creating an integer vector named pos to store the position of the previous index in the circular array
        int next = 0, cur = 0; // Initializing the variables next and cur

        // Finding the cycle starting point using BFS
        while (used.find(next) == used.end()) {
            used.insert(next); // Adding the current index to the unordered_set used
            idx[next] = cur; // Storing the current position in the idx vector
            pos[cur] = next; // Storing the previous position in the pos vector
            next = A[next]; // Moving to the next index
            cur++; // Incrementing the current position
        }

        long long a = (long long)cur - idx[next]; // Calculating the length of the cycle
        long long b = (long long)idx[next]; // Calculating the starting position of the cycle in the array
        int ans = (int)((10000 * a + K - b + MOD) % a + b); // Calculating the answer using the formula

        // Checking if the starting position of the cycle is greater than K, if yes then the answer is K
        if (b > K) {
            ans = (int)K;
        }

        cout << pos[ans] + 1 << endl; // Printing the position of the answer in the array
    }
};

int main() { // Defining the main method to start the execution of the program
    Main().doIt(); // Calling the doIt() method to execute the logic of the program
    return 0;
}

// <END-OF-CODE>
