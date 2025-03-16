
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[1000];  // Declare a character array to store the input string
    fgets(input, 1000, stdin);  // Read an input line (not used in further calculations)

    char *a = input;  // Assign the input string to a pointer variable 'a'

    int count = 0;  // Initialize a variable to store the count of '1's
    while (*a!= '\0') {  // Iterate through each character in the input string
        if (*a == '1') {  // Check if the current character is '1'
            count++;  // Increment the count of '1's
        }
        a++;  // Move to the next character in the input string
    }

    if (count == 0) {  // If there are no '1's, print 0
        printf("0\n");
    } else {
        int product = 1;  // Initialize a variable to store the product of counts of '0's between '1's
        char *start = input;  // Initialize a pointer variable to keep track of the start of each segment
        while (*a!= '\0') {  // Iterate through each character in the input string
            if (*a == '1') {  // Check if the current character is '1'
                int segmentCount = 0;  // Initialize a variable to store the count of '0's in the current segment
                while (start < a) {  // Iterate through each character in the current segment
                    if (*start == '0') {  // Check if the current character is '0'
                        segmentCount++;  // Increment the count of '0's in the current segment
                    }
                    start++;  // Move to the next character in the current segment
                }
                product *= (segmentCount + 1);  // Multiply the product by the count of '0's in the current segment plus 1
                start = a + 1;  // Move to the next character after the current '1'
            }
            a++;  // Move to the next character in the input string
        }
        printf("%d\n", product);  // Print the final product
    }

    return 0;
}
