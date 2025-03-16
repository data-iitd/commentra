#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<sstream>

using namespace std;

// Macro to simplify loop creation
#define reps(i,f,n) for(int i=f;i<int(n);i++)
#define rep(i,n) reps(i,0,n)

// Arrays to store the presence of numbers and dynamic programming results
int here[100001];
int dp1[100001];
int dp2[100001];

int main(){
    // Infinite loop to continuously process input until a termination condition is met
    while(1){
        int n, m;
        // Read the values of n and m
        cin >> n >> m;
        // Break the loop if n is 0 (termination condition)
        if(n == 0) break;
        
        // Initialize arrays to zero for the current test case
        rep(i, 100001) here[i] = dp1[i] = dp2[i] = 0;
        
        // Flag to check if a zero was encountered in the input
        bool dpflg = false;
        
        // Read m numbers and mark their presence
        rep(i, m){
            int a;
            cin >> a;
            // If a zero is encountered, set the flag
            if(a == 0) dpflg = true;
            // Mark the presence of number a
            here[a] = 1;
        }
        
        // Variables to track the maximum lengths of sequences
        int maxi1 = 0;
        int maxi2 = 0;
        
        // Calculate the longest sequence of present numbers without a zero
        reps(i, 1, n + 1){
            if(here[i] == 1) dp1[i] = dp1[i - 1] + 1; // Increment if present
            maxi1 = max(dp1[i], maxi1); // Update maximum length
        }
        
        // Calculate the longest sequence of present numbers considering the presence of a zero
        reps(i, 1, n + 1){
            if(here[i] == 1) dp2[i] = dp2[i - 1] + 1; // Increment if present
            else dp2[i] = dp1[i - 1] + 1; // Reset if zero is encountered
            maxi2 = max(dp2[i], maxi2); // Update maximum length
        }
        
        // Output the result based on whether a zero was encountered
        if(!dpflg){
            printf("%d\n", maxi1); // Print the maximum length without zero
        } else {
            printf("%d\n", maxi2); // Print the maximum length considering zero
        }
    }
}
