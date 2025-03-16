#include <stdio.h>
#include <stdbool.h>

#define rep(i,n) for(int i=0;i<n;i++) // Loop from 0 to n-1

// Segment representation for digits 0-9
<<<<<<< HEAD
bool seg[][7] = {
=======
bool seg[][7]={
>>>>>>> 98c87cb78a (data updated)
    {0,1,1,1,1,1,1}, // 0
    {0,0,0,0,1,1,0}, // 1
    {1,0,1,1,0,1,1}, // 2
    {1,0,0,1,1,1,1}, // 3
    {1,1,0,0,1,1,0}, // 4
    {1,1,0,1,1,0,1}, // 5
    {1,1,1,1,1,0,1}, // 6
    {0,1,0,0,1,1,1}, // 7
    {1,1,1,1,1,1,1}, // 8
    {1,1,0,1,1,1,1}  // 9
};

int main() {
    int n, t; // Declare variables for input and digit
    bool st[7]; // Array to store the state of segments

    // Read input until a negative number is encountered
<<<<<<< HEAD
    while (scanf("%d", &n), n >= 0) {
=======
    while(scanf("%d", &n), n >= 0) {
>>>>>>> 98c87cb78a (data updated)
        rep(i, 7) st[i] = 0; // Initialize segment states to 0

        // Process each digit input
        rep(i, n) {
            scanf("%d", &t); // Read the digit
            char ans[8] = {0}; // Initialize answer array to store segment states

            // Determine the segment states based on the input digit
            rep(i, 7) {
                // Calculate the current segment state and store it in ans
                ans[i] = (st[i] ^ seg[t][i]) ? '1' : '0'; 
                st[i] = seg[t][i]; // Update the current segment state
            }
            printf("%s\n", ans); // Output the segment states for the current digit
        }
    }

    return 0; // Return success
}

// <END-OF-CODE>
