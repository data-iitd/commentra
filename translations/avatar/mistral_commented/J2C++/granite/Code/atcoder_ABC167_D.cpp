

#include <bits/stdc++.h> // Including the necessary libraries

using namespace std; // Using the namespace std

const int MOD = 1000000007; // Defining a constant value for modulo arithmetic
const int MAX = INT_MAX; // Defining a constant value for maximum integer
const long LMAX = LLONG_MAX; // Defining a constant value for maximum long
const int LEN = 1000001; // Defining the length of an array

void doIt() { // Defining the method doIt() to contain the logic of the program
    int N; // Declaring the variable N to store the number of elements in the array
    long K; // Declaring the variable K to store the long value K
    int A[LEN]; // Declaring an integer array A of size LEN
    set<int> used; // Declaring a set named used to store the indices that have already been processed
    int idx[LEN]; // Declaring an integer array named idx to store the position of the current index in the circular array
    int pos[LEN]; // Declaring an integer array named pos to store the position of the previous index in the circular array
    int next = 0, cur = 0; // Initializing the variables next and cur

    cin >> N >> K; // Reading the number of elements in the array and the long value K

    // Reading the elements of the array A
    for (int i = 0; i < N; i++) {
        cin >> A[i]; // Reading the input and storing it in the array A
        A[i]--; // Subtracting 1 from the input to get the index of the previous element
    }

    // Finding the cycle starting point using BFS
    while (used.count(next) == 0) {
        used.insert(next); // Inserting the current index into the set used
        idx[next] = cur; // Storing the current position in the idx array
        pos[cur] = next; // Storing the previous position in the pos array
        next = A[next]; // Moving to the next index
        cur++; // Incrementing the current position
    }

    long a = cur - idx[next]; // Calculating the length of the cycle
    long b = idx[next]; // Calculating the starting position of the cycle in the array
    int ans = (10000 * a + K - b + MOD) % a + b; // Calculating the answer using the formula

    // Checking if the starting position of the cycle is greater than K, if yes then the answer is K
    if (b > K) {
        ans = K;
    }

    cout << pos[ans] + 1 << endl; // Printing the position of the answer in the array
}

int main() { // Defining the main method to start the execution of the program
    ios::sync_with_stdio(false); // Disabling synchronization between cin and cout
    cin.tie(0); // Setting the input stream to null
    doIt(); // Calling the doIt() method to execute the logic of the program
    return 0; // Returning 0 to indicate successful execution
}

