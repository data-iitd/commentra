import math

# This is the main function where the program starts execution
def main():
    # Initialize two float variables n and k to read input values
    n, k = map(float, input().split())

    # Calculate the number of digits required in k-base representation of number n
    # This is done by finding the smallest power of k such that k^x <= n and n < k^(x+1)

    # Initialize a variable x with initial value 0.0
    x = 0.0

    # Use a while loop to find the smallest power of k that satisfies the condition
    while True:
        # Calculate the lower and upper bounds of the current power of k
        under = math.pow(k, x)
        upper = math.pow(k, x + 1)

        # Check if the number n lies between under and upper bounds
        if under <= n < upper:
            # If the condition is satisfied, print the result (number of digits) and exit the function
            print(int(x + 1))
            return

        # If the condition is not satisfied, increment the value of x and continue the loop
        x += 1

# Call the main function to execute the program
if __name__ == "__main__":
    main()

# <END-OF-CODE>
