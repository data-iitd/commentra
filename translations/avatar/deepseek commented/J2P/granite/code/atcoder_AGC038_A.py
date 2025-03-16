
import sys # Importing sys for handling input and output

def main(): # Main function is the entry point of the program
    H, W, A, B = map(int, sys.stdin.readline().split()) # Reading the input values from the console

    # Checking if the matrix dimensions are suitable for the given values of A and B
    if W < 2 * A or H < 2 * B:
        print(-1) # Printing -1 if the matrix dimensions are not suitable
        return # Exiting the program

    # Nested loops to generate the matrix
    for i in range(H):
        for j in range(W):
            # Assigning 0 or 1 based on the conditions specified
            if (i < B and j < A) or (i >= B) and (j >= A):
                sys.stdout.write("0") # Writing 0 to the console
            else:
                sys.stdout.write("1") # Writing 1 to the console
        sys.stdout.write("\n") # Moving to the next line after each row is written

if __name__ == "__main__": # Executing the main function
    main() # Calling the main function

