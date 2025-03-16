# Import the sys module to read from standard input
import sys

# Continuously read pairs of integers until EOF (End of File) is reached
for line in sys.stdin:
    a, b = map(int, line.split())
    
    # Calculate the sum of the two integers
    x = a + b
    
    # Initialize a counter for the number of digits in the sum
    w = 0
    
    # Count the number of digits in the sum (x)
    while x:
        # Increment the digit counter
        w += 1
        # Remove the last digit from x by dividing by 10
        x //= 10
    
    # Print the number of digits in the sum
    print(w)

# <END-OF-CODE>
