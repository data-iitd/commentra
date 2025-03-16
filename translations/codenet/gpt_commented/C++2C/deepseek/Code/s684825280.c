#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define SIZE (1e5 * 2) + 13

// Declare a vector to hold the counts of each number
int* a;
// Declare a count array initialized to zero with a size of SIZE
int cnt[SIZE] = {0};

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

    // Declare a dynamic array to hold the counts of numbers that appeared at least once
    int a_size = 0;
    for(int i = 0; i < SIZE; ++i){
        if(cnt[i] > 0){
            a_size++;
        }
    }
    a = (int*)malloc(a_size * sizeof(int));

    // Transfer the counts of numbers that appeared at least once to array a
    int j = 0;
    for(int i = 0; i < SIZE; ++i){
        if(cnt[i] > 0){
            a[j++] = cnt[i]; // Add the count to array a
        }
    }

    // Initialize the answer variable to accumulate the result
    int ans = 0;
    // Sort the counts in ascending order
    std::sort(a, a + a_size);

    // Calculate the number of counts to exclude (m) based on k
    int m = a_size - k;
    // Sum the counts of the smallest m elements
    for(int i = 0; i < m; ++i){
        ans += a[i]; // Add the count to the answer
    }

    // Output the final answer
    printf("%d\n", ans);

    // Free the allocated memory for array a
    free(a);
}
