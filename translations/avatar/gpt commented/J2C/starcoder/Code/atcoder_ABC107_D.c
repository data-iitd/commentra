#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>

#define MAX(a, b) ((a) > (b)? (a) : (b))
#define MIN(a, b) ((a) < (b)? (a) : (b))
#define ABS(a) ((a) < 0? -(a) : (a))
#define SQR(a) ((a) * (a))
#define INF 1000000000
#define MOD 1000000007

typedef struct {
    int val;
    int cnt;
} BIT;

int solve(int *arr, int n) {
    // Get the length of the input array
    int n = arr.length;
    
    // Create a sorted copy of the input array
    int *sorted = (int *) malloc(n * sizeof(int));
    memcpy(sorted, arr, n * sizeof(int));
    qsort(sorted, n, sizeof(int), cmpfunc);
    
    // Calculate the total number of pairs possible in the array
    long total = (long) n * (n + 1) / 2;
    
    // Initialize pointers for binary search
    int l = 0, r = n - 1;
    
    // Perform binary search to find the median-like value
    while (l < r) {
        // Calculate the midpoint of the current search range
        int mid = l + (r - l) / 2;
        
        // Get the target value from the sorted array
        int target = sorted[mid];
        
        // Initialize counters for the current state
        int cur = 0;
        long cnt = 0;
        
        // Create a Binary Indexed Tree (BIT) for counting
        BIT *bit = (BIT *) malloc((2 * n + 2) * sizeof(BIT));
        
        // Initialize the BIT with base values
        for (int x = n + 1; x < bit.length; x += x & -x)
            bit[x].cnt++;
        
        // Count the number of elements less than or equal to the target
        for (int i = 0; i < n; i++) {
            cur += arr[i] <= target? 1 : -1;
            
            // Update the BIT with the current count
            for (int x = cur + n + 1; x < bit.length; x += x & -x)
                bit[x].cnt++;
            
            // Count the number of valid pairs using the BIT
            for (int x = cur + n; x > 0; x -= x & -x)
                cnt += bit[x].cnt;
        }
        
        // Adjust the search range based on the count of pairs
        if (cnt >= total / 2 + 1)
            r = mid; // Move left if count is sufficient
        else
            l = mid + 1; // Move right if count is insufficient
    }
    
    // Return the median-like value found
    return sorted[l];
}

int cmpfunc(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int main() {
    // Create a Scanner object to read input from the standard input stream
    Scanner scan = new Scanner(System.in);
    
    // Read the number of elements in the array
    int N = scan.nextInt();
    
    // Initialize an array to hold the input integers
    int[] arr = new int[N];
    
    // Populate the array with input integers
    for (int i = 0; i < N; i++)
        arr[i] = scan.nextInt();
    
    // Solve the task and print the result
    System.out.println(solve(arr, N));
    
    return 0;
}

