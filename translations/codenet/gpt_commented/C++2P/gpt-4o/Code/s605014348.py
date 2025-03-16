import math

# Function to find the smallest divisor of n
def div(n):
    # Check if n is even, return 2 if it is
    if n % 2 == 0:
        return 2

    # Calculate the square root of n for optimization
    s = int(math.sqrt(n))
    
    # Check for odd divisors from 3 up to the square root of n
    for i in range(3, s + 1, 2):
        # If i is a divisor of n, return it
        if n % i == 0:
            return i

    # If no divisors found, return n (n is prime)
    return n

def main():
    num = int(input())  # Read an integer from the user
    print(f"{num}:", end=" ")  # Output the initial number followed by a colon

    # Loop until num is reduced to 1
    while num != 1:
        # Find and output the smallest divisor of num
        smallest_divisor = div(num)
        print(smallest_divisor, end=" ")
        # Divide num by its smallest divisor
        num = num // smallest_divisor  # Use integer division

    print()  # Print a newline at the end of output

if __name__ == "__main__":
    main()

# <END-OF-CODE>
