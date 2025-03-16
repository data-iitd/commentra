#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<limits.h>
#include<ctype.h>
#include<time.h>

// Define a constant size for the count array
#define SIZE (1e5 * 2) + 13

// Declare a vector to hold the counts of each number
int *a;
// Declare a count array initialized to zero with a size of SIZE
int *cnt;

int main(){
    // Read the number of elements (n) and the number of largest counts to keep (k)
    int n, k;
    scanf("%d %d", &n, &k);

    // Read n integers and count their occurrences
    for(int i = 0; i < n; ++i){
        int x;
        scanf("%d", &x);
        // Increment the count for the number x
        cnt[x]++;
    }

    // Transfer the counts of numbers that appeared at least once to vector a
    for(int i = 0; i < cnt.size(); ++i){
        if(cnt[i] > 0)
            a.push_back(cnt[i]); // Add the count to vector a
    }

    // Initialize the answer variable to accumulate the result
    int ans = 0;
    // Sort the counts in ascending order
    sort(a.begin(), a.end());

    // Calculate the number of counts to exclude (m) based on k
    int m = a.size() - k;
    // Sum the counts of the smallest m elements
    for(int i = 0; i < m; ++i){
        ans += a[i]; // Add the count to the answer
    }

    // Output the final answer
    printf("%d\n", ans);
}

