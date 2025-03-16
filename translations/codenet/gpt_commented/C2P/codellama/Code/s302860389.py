#include <stdio.h>
#include <stdlib.h>

int main()
{
    # Declare variables to hold input numbers and intermediate values
    inputNumbers = input("Enter a string of numbers: ")
    a, b, c, d = inputNumbers[0], inputNumbers[1], inputNumbers[2], inputNumbers[3]
    sum = 0
    symbols = []
    
    # Iterate through all combinations of addition and subtraction for the four numbers
    for i in range(2): # Loop for the first operation (a + b or a - b)
        for j in range(2): # Loop for the second operation (result + c or result - c)
            for k in range(2): # Loop for the third operation (result + d or result - d)
                # Determine the first operation (addition or subtraction with a and b)
                if i == 0:
                    sum = a + b
                    symbols.append('+') # Store the symbol used
                else:
                    sum = a - b
                    symbols.append('-') # Store the symbol used
                
                # Determine the second operation (addition or subtraction with c)
                if j == 0:
                    sum = sum + c
                    symbols.append('+') # Store the symbol used
                else:
                    sum = sum - c
                    symbols.append('-') # Store the symbol used
                
                # Determine the third operation (addition or subtraction with d)
                if k == 0:
                    sum = sum + d
                    symbols.append('+') # Store the symbol used
                else:
                    sum = sum - d
                    symbols.append('-') # Store the symbol used
                
                # Check if the calculated sum equals 7
                if sum == 7:
                    # Print the expression that results in 7
                    print(f"{a}{symbols[0]}{b}{symbols[1]}{c}{symbols[2]}{d}=7")
                    
                    return 0 # Exit the program after finding the first valid expression
            }
        }
    }

    return 0 # Return 0 to indicate successful execution
}

