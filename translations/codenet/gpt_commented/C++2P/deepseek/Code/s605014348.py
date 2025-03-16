def div(n):
    # Check if n is even, return 2 if it is
    if n % 2 == 0:
        return 2

    # Calculate the square root of n for optimization
    s = int(n**0.5)
    
    # Check for odd divisors from 3 up to the square root of n
    for i in range(3, s + 1, 2):
        # If i is a divisor of n, return it
        if n % i == 0:
            return i

    # If no divisors found, return n (n is prime)
    return n

def main():
    # Read an integer from the user
    num = int(input())
    # Output the initial number followed by a colon
    print(num, end=':')

    # Loop until num is reduced to 1
    while num != 1:
        # Find and output the smallest divisor of num
        print(" " + str(div(num)), end='')
        # Divide num by its smallest divisor
        num = num // div(num)

    # Print a newline at the end of output
    print()

main()
