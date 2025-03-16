#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read a single line of input and convert it to a tuple of integers
void read_value(int *a, int *b) {
    scanf("%d %d", a, b);
}

// Function to read a single line of input and return a list of integers
void read_values(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

// Function to read a single integer from input
int read_int() {
    int num;
    scanf("%d", &num);
    return num;
}

// Function to read a single line of input and return it as a string
char* read_string() {
    char *str = (char*)malloc(10000 * sizeof(char));
    scanf("%s", str);
    return str;
}

// Helper function to determine if a specific arrangement is possible
int help(int a, int b, int *l, int l_size) {
    int tot[b][a];
    int count = 0;
    
    // Create subarrays of size 'a' from the array 'l'
    for (int i = 0; i < b; i++) {
        for (int j = 0; j < a; j++) {
            tot[i][j] = l[count++];
        }
    }
    
    // Check if any combination of the subarrays sums to 'b'
    for (int i = 0; i < a; i++) {
        int sum = 0;
        for (int j = 0; j < b; j++) {
            sum += tot[j][i];
        }
        if (sum == b) {
            return 1;
        }
    }
    return 0;
}

// Main function to solve the problem
void solve() {
    char *x = read_string();  // Read the input string
    int s[strlen(x)];
    
    // Convert the input string into an array of integers (0 for 'O', 1 for 'X')
    for (int i = 0; i < strlen(x); i++) {
        if (x[i] == 'O') {
            s[i] = 0;
        } else {
            s[i] = 1;
        }
    }
    
    // Check for all divisors of 12 to find valid arrangements
    for (int i = 1; i <= 12; i++) {
        if (12 % i == 0) {  // Check if 'i' is a divisor of 12
            if (help(i, 12 / i, s, strlen(x))) {  // Use the helper function to check arrangements
                printf("%d %dx%d ", 12 / i, i, 12 / i);  // Print valid arrangements
            }
        }
    }
    printf("\n");  // Print a newline at the end
}

// Entry point of the program
int main() {
    // Read the number of test cases and solve each case
    int t = read_int();
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}
