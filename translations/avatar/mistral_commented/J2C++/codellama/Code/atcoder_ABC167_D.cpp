
#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <bitset>
#include <limits>
#include <iomanip>
#include <cassert>
using namespace std;

const int MOD = 1000000007; // Defining a constant value for modulo arithmetic
const int MAX = INT_MAX; // Defining a constant value for maximum integer
const long LMAX = LONG_MAX; // Defining a constant value for maximum long
const int len = 1e6 + 1; // Defining the length of an array

void doIt() { // Defining the method doIt() to contain the logic of the program
    int N; // Defining an integer variable N
    long K; // Defining a long variable K
    cin >> N >> K; // Reading the number of elements in the array and the long value K
    int A[N]; // Creating an integer array A of size N

    // Reading the elements of the array A
    for (int i = 0; i < N; i++) {
        cin >> A[i]; // Reading the elements of the array A
        A[i]--; // Subtracting 1 from the input to get the index of the previous element
    }

    set<int> used; // Creating a set named used to store the indices that have already been processed
    int idx[N]; // Creating an integer array named idx to store the position of the current index in the circular array
    int pos[N]; // Creating an integer array named pos to store the position of the previous index in the circular array
    int next = 0, cur = 0; // Initializing the variables next and cur

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
    int ans = (int) (10000 * a + K - b + MOD) % a + b; // Calculating the answer using the formula

    // Checking if the starting position of the cycle is greater than K, if yes then the answer is K
    if (b > K) {
        ans = (int) K;
    }

    cout << pos[ans] + 1 << endl; // Printing the position of the answer in the array
}

int main() { // Defining the main method to start the execution of the program
    doIt(); // Calling the doIt() method to execute the logic of the program
    return 0;
}

