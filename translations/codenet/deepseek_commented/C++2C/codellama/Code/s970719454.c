#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Declare arrays to store information
int here[100001]; // To mark the presence of elements
int dp1[100001]; // Dynamic programming array 1
int dp2[100001]; // Dynamic programming array 2

int main(){
    // Main loop to read input values
    while(1){
        int n, m;
        scanf("%d %d", &n, &m);
        if(n == 0) break; // Break the loop if n is 0
        
        // Initialize arrays for each iteration
        rep(i, 100001) here[i] = dp1[i] = dp2[i] = 0;
        
        // Flag to determine behavior based on input
        bool dpflg = false;
        
        // Read m values and mark them in 'here'
        rep(i, m){
            int a;
            scanf("%d", &a);
            if(a == 0) dpflg = true; // Set flag if any value is 0
            here[a] = 1;
        }
        
        // Variables to store maximum lengths of sequences
        int maxi1 = 0;
        int maxi2 = 0;
        
        // Calculate maximum length of sequences in dp1
        reps(i, 1, n + 1){
            if(here[i] == 1) dp1[i] = dp1[i - 1] + 1;
            maxi1 = max(dp1[i], maxi1);
        }
        
        // Calculate maximum length of sequences in dp2
        reps(i, 1, n + 1){
            if(here[i] == 1) dp2[i] = dp2[i - 1] + 1;
            else dp2[i] = dp1[i - 1] + 1;
            maxi2 = max(dp2[i], maxi2);
        }
        
        // Output the result based on the value of dpflg
        if(!dpflg){
            printf("%d\n", maxi1);
        } else {
            printf("%d\n", maxi2);
        }
    }
}

