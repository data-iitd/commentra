import sys

# Set the maximum recursion limit to a high value to handle deep recursions if necessary
sys.setrecursionlimit(10**7)

# Function to read a list of integers from input
def LI(): 
    return [int(x) for x in sys.stdin.readline().split()]

# Function to read a list of integers from input and adjust them to be zero-indexed
def LI_(): 
    return [int(x) - 1 for x in sys.stdin.readline().split()]

# Function to read a list of floats from input
def LF(): 
    return [float(x) for x in sys.stdin.readline().split()]

# Function to read a list of strings from input
def LS(): 
    return sys.stdin.readline().split()

# Function to read a single integer from input
def II(): 
    return int(sys.stdin.readline())

# Function to read a single string from input and strip whitespace
def SI(): 
    return sys.stdin.readline().strip()

# Define a large constant for infinity
INF = 10 ** 18

# Define a constant for modulo operations
MOD = 10 ** 9 + 7

def main(): 
    # Read the number of elements
    N = II()
    
    # Read the list of integers
    a_li = LI()

    # Sort the list of integers
    a_li.sort()

    # Get the maximum value from the sorted list
    n = a_li[-1]
    
    # Initialize the minimum difference to infinity
    dif = INF
    prev_dif = dif
    
    # Iterate through the list except the last element
    for a in a_li[:-1]:
        # Calculate the difference between half of the maximum value and the current element
        dif = min(abs(n/2 - a), dif)
        
        # If the current difference is different from the previous difference
        if dif != prev_dif:
            # Update the result with the current element
            r = a
            # Update the previous difference
            prev_dif = dif

    # Print the maximum value and the element that gives the minimum difference
    print(n, r)

# Call the main function to execute the program
main()
