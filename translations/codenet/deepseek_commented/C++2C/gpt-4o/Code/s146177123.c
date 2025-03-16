#include <stdio.h>
#include <stdbool.h>

#define rep(i,n) for(int i=0;i<n;i++)

// Array to represent the segments of the digits 0-9
bool seg[][7]={
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
    int n, t;
    bool st[7];
    
    while (scanf("%d", &n), n != -1) { // Read the number of digits and check if it's not -1
        // Initialize the state array to represent the current display state
        rep(i, 7) st[i] = 0;
        
        rep(i, n) {
            scanf("%d", &t); // Read the next digit
            char ans[8] = {0}; // Array to store the current display state
            
            rep(i, 7) {
                // Calculate the current segment state and store it in the answer array
                ans[i] = (st[i] ^ seg[t][i]) ? '1' : '0';
                // Update the state array with the current segment state
                st[i] = seg[t][i];
            }
            // Output the current display state
            printf("%s\n", ans);
        }
    }
    
    return 0;
}

// <END-OF-CODE>
