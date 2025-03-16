# Function to return the absolute value of an integer
def abs_value(x):
    if x < 0:
        # If the input integer is negative, return its negation
        return -x
    # Otherwise, return the input integer as it is
    return x

# Function to return the minimum of two integers
def min_value(a, b):
    if a > b:
        # If the first integer is greater than the second, return the second
        return b
    # Otherwise, return the first integer
    return a

# Main function
if __name__ == "__main__":
    # Declare and initialize two integer variables, N and K, using input
    N, K = map(int, input().split())

    # Declare and initialize an integer variable, x, with the value of N modulo K
    x = N % K

    # Call the abs_value function to get the absolute value of x if it's negative
    x = abs_value(x)

    # Call the min_value function to find the minimum between x and abs_value(x-K)
    x = min_value(abs_value(x - K), x)

    # Print the result
    print(x)

# <END-OF-CODE>
