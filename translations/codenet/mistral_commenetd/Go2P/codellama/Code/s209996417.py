// This is the main function where the program starts execution
def main():
    # Initialize two float64 variables n and k to read input values
    n = 0.0
    k = 0.0

    # Read input values n and k from the standard input using input()
    n = float(input())
    k = float(input())

    # Calculate the number of digits required in k-base representation of number n
    # This is done by finding the smallest power of k such that k^x <= n and n < k^(x+1)

    # Initialize a float64 variable x with initial value 0.0
    x = 0.0

    # Use a for loop to find the smallest power of k that satisfies the condition
    while True:
        # Calculate the lower and upper bounds of the current power of k
        under = pow(k, x)
        upper = pow(k, x+1)

        # Check if the number n lies between under and upper bounds
        if under <= n and n < upper:
            # If the condition is satisfied, print the result (number of digits) and exit the function
            print(x+1)
            return

        # If the condition is not satisfied, increment the value of x and continue the loop
        x += 1

# 