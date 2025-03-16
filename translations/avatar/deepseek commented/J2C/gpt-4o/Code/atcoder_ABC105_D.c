#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000

// Function to read an integer from input
int readInt() {
    int x;
    scanf("%d", &x);
    return x;
}

// Function to read an array of integers from input
void readIntArray(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = readInt();
    }
}

// Structure to hold the frequency of remainders
typedef struct {
    int key;
    int value;
} HashMapEntry;

HashMapEntry dp[MAX_N];
int dpSize = 0;

// Function to find the frequency of a remainder in the HashMap
int getFrequency(int key) {
    for (int i = 0; i < dpSize; i++) {
        if (dp[i].key == key) {
            return dp[i].value;
        }
    }
    return 0;
}

// Function to update the frequency of a remainder in the HashMap
void updateFrequency(int key, int increment) {
    for (int i = 0; i < dpSize; i++) {
        if (dp[i].key == key) {
            dp[i].value += increment;
            return;
        }
    }
    dp[dpSize].key = key;
    dp[dpSize].value = increment;
    dpSize++;
}

int main() {
    // Read the number of elements and the modulo value
    int n = readInt();
    int m = readInt();
    
    // Read the array of elements
    int a[MAX_N];
    readIntArray(a, n);
    
    // Initialize the answer and base variable
    long long ans = 0;
    int base = 0;
    
    // Iterate through the array to calculate the answer
    for (int i = 0; i < n; i++) {
        // Update the base variable
        base = (base - a[i] % m + m) % m;
        
        // Update the frequency of remainders in the HashMap
        updateFrequency((base + a[i]) % m, 1);
        
        // Add the frequency of the current remainder to the answer
        ans += getFrequency(base);
    }
    
    // Print the final answer
    printf("%lld\n", ans);
    
    return 0;
}

// <END-OF-CODE>
