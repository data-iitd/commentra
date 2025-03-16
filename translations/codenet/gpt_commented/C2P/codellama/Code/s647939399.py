#include<stdio.h>

int main() {
    char m; // Variable to store the operator
    int a, b, c[256], i, j; // Variables for operands, results array, and loop counters

    # Infinite loop to continuously read input until a termination condition is met
    for(i = 0; i > -1; i++) {
        # Read two integers and an operator from the user
        scanf("%d %c %d", &a, &m, &b);
        
        # Check if the operator is '?' to terminate the loop
        if(m == '?'):
            break; # Exit the loop if the termination operator is encountered
        }
        
        # Perform addition if the operator is '+'
        if(m == '+'):
            c[i] = a + b; # Store the result of addition in the results array
        }
        
        # Perform subtraction if the operator is '-'
        if(m == '-'):
            c[i] = a - b; # Store the result of subtraction in the results array
        }
        
        # Perform multiplication if the operator is '*'
        if(m == '*'):
            c[i] = a * b; # Store the result of multiplication in the results array
        }
        
        # Perform division if the operator is '/'
        if(m == '/'):
            c[i] = a / b; # Store the result of division in the results array
        }
    }
    
    # Print all results stored in the results array
    for(j = 0; j < i; j++) {
        printf("%d\n", c[j]); # Output each result on a new line
    }
    
    return(0); # Return success
}

