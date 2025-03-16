import math

# Function to check if a number is prime
def walk_on_multiplication_table(num):
    # Initialize divisor variable
    div = 0

    # Check divisibility of the number with the square root of the number
    for i in range(int(math.sqrt(num)), 1, -1):
        # Check if the number is divisible by the current number
        if num % i == 0:
            # If yes, then the current number is divisor
            div = i
            # Break the loop as we have found the divisor
            break

    # If the number is not divisible by any number till the square root, then it is a prime number
    if div == 0:
        # Return the number - 1 as 0 is not considered as a prime number
        return num - 1

    # If the number is divisible by some number, then it is not a prime number
    # Return the divisor + number/divisor - 2 as the prime number
    return div + num // div - 2

# Main function to read the number and print the prime number
def main():
    # Initialize a variable to read the number
    a = int(input())

    # Print the prime number using the walk_on_multiplication_table function
    print(walk_on_multiplication_table(a))

# Call the main function
main()

