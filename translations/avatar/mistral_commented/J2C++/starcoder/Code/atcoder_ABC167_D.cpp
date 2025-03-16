
#include <bits/stdc++.h> // Importing the standard library

using namespace std; // Using the standard library

int main() { // Defining the main method to start the execution of the program
    int N, K; // Declaring the variables N and K
    cin >> N >> K; // Reading the input from the user
    int A[N]; // Declaring the array A of size N
    for (int i = 0; i < N; i++) { // Looping through the array A
        cin >> A[i]; // Reading the input from the user
    }

    int idx[N], pos[N]; // Declaring the arrays idx and pos of size N
    int next = 0, cur = 0; // Declaring the variables next and cur
    set<int> used; // Declaring the set used to store the indices that have already been processed

    // Finding the cycle starting point using BFS
    while (!used.count(next)) {
        used.insert(next); // Adding the current index to the set used
        idx[next] = cur; // Storing the current position in the idx array
        pos[cur] = next; // Storing the previous position in the pos array
        next = A[next]; // Moving to the next index
        cur++; // Incrementing the current position
    }

    long a = (long) cur - idx[next]; // Calculating the length of the cycle
    long b = (long) idx[next]; // Calculating the starting position of the cycle in the array
    int ans = (int) (10000 * a + K - b + 1000000007) % a + b; // Calculating the answer using the formula

    // Checking if the starting position of the cycle is greater than K, if yes then the answer is K
    if (b > K) {
        ans = (int) K;
    }

    cout << pos[ans] + 1 << endl; // Printing the position of the answer in the array
    return 0;
}

