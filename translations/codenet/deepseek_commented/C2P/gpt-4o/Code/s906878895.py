import sys

for line in sys.stdin:  # Read lines from standard input until EOF
    a, b = map(int, line.split())  # Split the line into two integers
    x = a + b  # Calculate the sum of the two integers
    w = 0  # Initialize the digit count to 0
    while x:  # Loop to count the number of digits in the sum
        w += 1  # Increment the digit count
        x //= 10  # Divide the sum by 10 to remove the last digit
    print(w)  # Print the number of digits in the sum

# <END-OF-CODE>
