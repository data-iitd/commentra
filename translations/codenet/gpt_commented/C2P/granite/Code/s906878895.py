
# Python code to calculate the number of digits in the sum of two integers

# Continuously read pairs of integers until EOF (End of File) is reached
while True:
    try:
        # Read two integers from the user
        a, b = map(int, input().split())
        
        # Calculate the sum of the two integers
        x = a + b
        
        # Initialize a counter for the number of digits in the sum
        w = 0
        
        # Count the number of digits in the sum (x)
        while x > 0:
            # Increment the digit counter
            w += 1
            # Remove the last digit from x by dividing by 10
            x //= 10
        
        # Print the number of digits in the sum
        print(w)
    except EOFError:
        # Break the loop when EOF is reached
        break

# End of Python code
