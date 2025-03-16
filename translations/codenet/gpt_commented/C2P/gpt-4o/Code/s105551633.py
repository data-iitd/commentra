import math

# Function to count the number of digits in a given integer
def digit(n):
    res = 0  # Initialize digit count to zero
    # Loop until all digits are processed
    while n > 0:
        res += 1  # Increment digit count
        n //= 10  # Remove the last digit
    return res  # Return the total count of digits

# Function to execute the main logic of the program
def run():
    n = int(input())  # Read a long long integer from standard input
    
    # Initialize minimum digit count with the digit count of n
    min_digits = digit(n)

    # Loop through all possible divisors of n
    for i in range(1, int(math.isqrt(n)) + 1):
        # Skip if i is not a divisor of n
        if n % i != 0:
            continue
        
        # Calculate the corresponding divisor
        a = i
        b = n // i

        # Update the minimum digit count based on the digits of the divisors
        min_digits = min(min_digits, max(digit(a), digit(b)))
    
    # Print the minimum digit count found
    print(min_digits)

# Main function to start the program execution
if __name__ == "__main__":
    run()  # Call the run function to execute the logic

# <END-OF-CODE>
