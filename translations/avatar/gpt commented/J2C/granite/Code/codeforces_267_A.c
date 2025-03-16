
#include <stdio.h> // Include the standard input/output library

int sub(int a, int b) {
    int min = (a < b)? a : b;
    int max = (a > b)? a : b;
    int result = 0;
    
    while (min > 0) {
        result += max / min;
        max = max % min;
        int curr_min = (min < max)? min : max;
        int curr_max = (min > max)? min : max;
        min = curr_min;
        max = curr_max;
    }
    
    return result;
}

int main() {
    int n;
    scanf("%d", &n); // Read the number of test cases from user input
    
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b); // Read two integers a and b from user input
        
        printf("%d\n", sub(a, b)); // Call the sub method and print the result
    }
    
    return 0;
}

