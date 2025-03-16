
import math
import sys

# Initialize scanner to read input from standard input
sc = sys.stdin

# Main method is the entry point of the Python application
def main():
    # Read the first integer N from the standard input
    N = int(sc.readline().strip())

    # Read the second integer K from the standard input
    K = int(sc.readline().strip())

    # Read the string S from the standard input
    S = sc.readline().strip()

    # Initialize a boolean variable firstTime to true
    firstTime = True

    # Initialize an integer variable step to 1
    step = 1

    # Perform the main logic while K is greater than zero
    while K > 0:
        # Create a new string T to store the reversed version of S
        T = S[::-1]

        # Create a new string revU to store the concatenation of S and T reversed
        revU = S + T

        # Create a string variable sDash to store the current substring of revU
        sDash = S

        # Iterate through the substrings of revU starting from the end of S
        for i in range(N, -1, -step):
            # Get the substring of revU starting from the current index i and of length N
            tmp = revU[i:i+N]

            # Compare the current substring tmp with the current substring sDash
            if sDash > tmp:
                # Update the current substring sDash with the new substring tmp
                sDash = tmp
            else:
                # If this is not the first iteration, break the loop
                if not firstTime:
                    break

        # Perform some actions based on the comparison of sDash and S
        if firstTime:
            firstTime = False
            # Check if the length of S raised to the power of K is greater than N
            if math.pow(2, K) > N:
                # Print the first character of S N times and exit the program
                c = sDash[0]
                for i in range(N):
                    print(c, end='')
                print()
                sys.exit(0)
        else:
            # Update the value of step
            step += step

        # Decrement the value of K
        K -= 1

        # Update the value of S to be the current substring sDash reversed
        S = sDash[::-1]

    # Print the reversed version of the final string S
    print(S)

if __name__ == '__main__':
    main()

