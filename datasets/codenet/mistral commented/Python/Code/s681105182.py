# Set the recursion limit for the function call stack to a large value
import sys
sys.setrecursionlimit(10**7)

# Define a helper function to read a list of integers from standard input
def LI():
    """
    Reads a list of integers from standard input and returns it as a list.
    """
    return [int(x) for x in sys.stdin.readline().split()]

# Define a helper function to read a list of integers from standard input,
# but subtract 1 from each integer
def LI_():
    """
    Reads a list of integers from standard input, subtracts 1 from each integer,
    and returns it as a list.
    """
    return [int(x) - 1 for x in sys.stdin.readline().split()]

# Define a helper function to read a list of floats from standard input
def LF():
    """
    Reads a list of floats from standard input and returns it as a list.
    """
    return [float(x) for x in sys.stdin.readline().split()]

# Define a helper function to read a list of strings from standard input
def LS():
    """
    Reads a list of strings from standard input and returns it as a list.
    """
    return sys.stdin.readline().split()

# Define a helper function to read an integer from standard input
def II():
    """
    Reads an integer from standard input and returns it.
    """
    return int(sys.stdin.readline())

# Define a helper function to read a string from standard input
def SI():
    """
    Reads a string from standard input and returns it as a string.
    """
    return sys.stdin.readline().strip()

# Define a constant for a very large number
INF = 10 ** 18

# Define a constant for the modulus value
MOD = 10 ** 9 + 7

# Define the main function
def main():
    """
    The main function reads the number of integers N from standard input,
    reads a list of N integers from standard input, sorts the list in ascending order,
    finds the difference between the largest integer and the middle integer,
    and prints the largest integer and the middle integer.
    """
    N = II()
    a_li = LI()

    # Sort the list of integers in ascending order
    a_li.sort()

    # Get the largest integer in the list
    n = a_li[-1]

    # Initialize the difference between the largest integer and the middle integer to infinity
    dif = INF

    # Initialize a variable to keep track of the previous difference
    prev_dif = dif

    # Iterate through the list of integers, starting from the second to last integer
    for a in a_li[:-1]:
        # Calculate the difference between the largest integer and the current integer
        dif = min(abs(n/2 - a), dif)

        # If the difference is not the same as the previous difference, update the variables r and prev_dif
        if dif != prev_dif:
            r = a
            prev_dif = dif

    # Print the largest integer and the middle integer
    print(n, r)

# Call the main function
main()