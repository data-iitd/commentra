
# Python code to solve the problem

# Function to count the number of digits in a given integer
def digit(n):
    res = 0  # Initialize digit count to zero
    while n > 0:
        res += 1  # Increment digit count
        n //= 10  # Remove the last digit
    return res  # Return the total count of digits

# Function to execute the main logic of the program
def run():
    n = int(input())  # Read a long long integer from standard input
    min_digit = digit(n)  # Initialize minimum digit count with the digit count of n
    i = 1
    while i * i <= n:
        if n % i!= 0:  # Skip if i is not a divisor of n
            i += 1
            continue
        a = i
        b = n // i
        min_digit = min(min_digit, max(digit(a), digit(b)))  # Update the minimum digit count based on the digits of the divisors
        i += 1
    print(min_digit)  # Print the minimum digit count found

# Main function to start the program execution
if __name__ == "__main__":
    run()  # Call the run function to execute the logic

