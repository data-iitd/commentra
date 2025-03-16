#include <stdio.h>

int main() {
    // Step 3: Create an array of integers with a size of 3
    int in[3];
    
    // Step 4: Prompt the user to input three integers
    scanf("%d %d %d", &in[0], &in[1], &in[2]);
    
    // Step 5: Sort the array of integers in ascending order
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2 - i; j++) {
            if (in[j] > in[j + 1]) {
                int temp = in[j];
                in[j] = in[j + 1];
                in[j + 1] = temp;
            }
        }
    }
    
    // Step 6: Perform a calculation using the sorted integers and print the result
    printf("%d\n", in[2] * 10 + in[1] + in[0]);
    
