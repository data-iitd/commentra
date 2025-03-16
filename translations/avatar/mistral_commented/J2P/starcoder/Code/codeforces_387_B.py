# Import necessary Python utility classes
import sys
import math

# Main method is the entry point of the Python application
def main ( ):
    # Read the number of requests and preemptions from the input
    n = int ( input ( ) )
    m = int ( input ( ) )

    # Create lists to store request and preemption indices
    req = [ ]
    pre = [ ]

    # Read request indices and store them in the list
    for i in range ( n ):
        req.append ( int ( input ( ) ) )
        # Comment: Read and store request index i

    # Read preemption indices and store them in the list
    for i in range ( m ):
        pre.append ( int ( input ( ) ) )
        # Comment: Read and store preemption index i

    # Initialize index variables for requests and preemptions
    i = n - 1
    j = m - 1

    # Initialize answer variable
    ans = 0

    # While there are still requests and preemptions to compare
    while i >= 0 and j >= 0:
        # If the current request can preempt the current preemption
        if req[i] > pre[j]:
            # Increment answer variable
            ans += 1
        else:
            # Decrement preemption index
            j -= 1
        # Decrement request index
        i -= 1

    # Print the answer and the number of remaining requests
    print ( ans + i + 1 )

# Entry point of the program
if __name__ == "__main__":
    main ( )

