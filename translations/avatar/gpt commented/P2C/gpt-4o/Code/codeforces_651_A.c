#include <stdio.h>

int main() {
    int x, y;
    
    // Read two integers from input and assign them to x and y
    scanf("%d %d", &x, &y);
    
    // Calculate the maximum value based on the formula and print it
    // The formula computes x + y - 3 and adjusts based on the difference between y and x
    // It ensures the result is not negative by taking the maximum with 0
    int result = x + y - 3 + ((y - x) % 3 > 0);
    printf("%d\n", result < 0 ? 0 : result);
    
    return 0;
}

// Define a function to read a single integer from input
int num_inp() {
    int num;
    scanf("%d", &num);
    return num;
}

// Define a function to read a list of integers from input
void arr_inp(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
}

// Define a function to read a space-separated list of integers from input
void sp_inp(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
}

// Define a function to read a string from input
void str_inp(char *str, int size) {
    scanf("%s", str);
}

// <END-OF-CODE>
