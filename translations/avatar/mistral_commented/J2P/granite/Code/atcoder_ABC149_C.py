
# Importing necessary libraries
import math

# Main method is the entry point of the Python application
def main():
    # Reading an integer input from the user
    x = int(input())

    # Checking if the number is even and not equal to 2
    if x!= 2 and x % 2 == 0:
        x += 1  # Increment the number if it's even and not 2

    # Starting an infinite loop
    while True:
        i = 3  # Declaring an integer variable 'i'
        sqrt_num = math.sqrt(x)  # Calculating the square root of the number 'x'

        # Checking for prime numbers using trial division method
        while i <= sqrt_num:
            if x % i == 0:  # Checking if the number 'x' is divisible by 'i'
                break  # If it's divisible, then 'i' is a factor and the loop is broken
            i += 2  # Incrementing 'i' by 2 to check the next odd number

        # If 'i' is greater than the square root, then the number 'x' is prime
        if i > sqrt_num:
            break  # Exiting the loop

        # If the loop didn't break, then the number 'x' is not prime, so we need to find the next prime number
        x += 2  # Incrementing the number by 2 to check the next odd number

    # Printing the prime number found
    print(x)

# Calling the main method to start the program
if __name__ == "__main__":
    main()

