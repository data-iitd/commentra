#include <stdio.h>

int main() {
    // Declare a variable to store the input data
    int data;
    
    // Read an integer value from the standard input and store it in `data`
    scanf("%d", &data);
    
    // Calculate the cube of `data` and store the result in `result`
    int result = data * data * data;
    
    // Print the result
    printf("%d\n", result);
    
    return 0;
}
