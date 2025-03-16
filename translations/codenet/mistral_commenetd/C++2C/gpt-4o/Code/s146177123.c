#include <stdio.h>
#include <stdbool.h>

#define rep(i,n) for(int i=0;i<n;i++) // A macro for looping through a range of indices

bool seg[7][7] = { // A 2D boolean array representing the segment tree
    {0,1,1,1,1,1,1},
    {0,0,0,0,1,1,0},
    {1,0,1,1,0,1,1},
    {1,0,0,1,1,1,1},
    {1,1,0,0,1,1,0},
    {1,1,0,1,1,0,1},
    {1,1,1,1,1,0,1},
    {0,1,0,0,1,1,1},
    {1,1,1,1,1,1,1},
    {1,1,0,1,1,1,1}
};

int main() {
    int n, t; // Variables to store the number of test cases and the current test case
    bool st[7]; // A boolean array to store the current segment tree state

    while (scanf("%d", &n), n != -1) { // Reading the number of test cases and processing them while there are still test cases to be processed
        rep(i, 7) st[i] = 0; // Initializing the segment tree state to all zeros
        rep(i, n) { // Processing each test case
            scanf("%d", &t); // Reading the current test case
            char ans[8] = {0}; // Initializing an array to store the answer as a string of 0s and 1s
            rep(i, 7) { // Iterating through each bit position in the segment tree
                ans[i] = (st[i] ^ seg[t][i]) ? '1' : '0'; // Updating the answer based on the current segment tree state and the current test case
                st[i] = seg[t][i]; // Updating the segment tree state for the current bit position
            }
            printf("%s\n", ans); // Printing the answer for the current test case
        }
    }

    return 0; // Indicating successful termination of the program
}

// <END-OF-CODE>
