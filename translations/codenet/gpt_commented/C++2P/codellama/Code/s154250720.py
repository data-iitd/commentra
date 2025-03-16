#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;

#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;

// Define constants for maximum size and infinity value
const int maxn=200000+10;
const int INF=int(1e8);

// Arrays to hold input values and sorted values
int maps[maxn];
int num[maxn];

int main() {
    int n; // Variable to hold the number of elements
    
    // Continuously read input until EOF
    while(~scanf("%d",&n)) {
        // Read n integers into the maps array and copy to num array
        for(int i=1; i<=n; i++) {
            scanf("%d",&maps[i]);
            num[i]=maps[i];
        }

        // Sort the maps array to find the median
        sort(maps+1,maps+n+1);
        
        // Calculate the index for the median element
        int m=n/2;

        // For each element in the original array, determine and print the appropriate value
        for(int i=1; i<=n; i++) {
            // If the current number is less than or equal to the median
            if(num[i]<=maps[m])
                // Print the next higher number (the one after the median)
                printf("%d\n",maps[m+1]);
            else
                // Print the median value
                printf("%d\n",maps[m]);
        }
    }
    return 0; // Return success
}

