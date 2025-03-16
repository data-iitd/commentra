# Import the sys module for input and output operations.
import sys

# The main function is the entry point of the program.
def main():
    # Take input from the user for variables A and B.
    A, B = map(int, sys.stdin.readline().split())
    
    # Calculate the sum of A and B and store it in variable C.
    C = A + B
    
    # Check if neither A, B, nor the sum C is divisible by 3.
    if A % 3 != 0 and B % 3 != 0 and C % 3 != 0:
        # If the condition is true, print "Impossible" to the console.
        print("Impossible")
    else:
        # Otherwise, print "Possible" to the console.
        print("Possible")

# Call the main function to execute the program.
if __name__ == "__main__":
    main()

# <END-OF-CODE>
