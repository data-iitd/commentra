
import sys

def main():
    N = int(input()) # Read the integer N
    K = int(input()) # Read the integer K
    S = input() # Read the string S
    firstTime = True # Initialize a flag to check if it's the first time through the loop
    step = 1 # Initialize the step size

    # Main loop to manipulate the string based on the value of K
    while K > 0:
        T = S[::-1] # Reverse the string S
        U = S + T # Concatenate S with its reverse
        U = U[::-1] # Reverse the concatenated string
        sDash = S # Initialize sDash with the original string S

        # Iterate over the reversed concatenated string to find the best substring
        for i in range(N, -1, -step):
            tmp = U[i:i+N] # Get a substring of length N
            if sDash > tmp: # Compare lexicographically
                sDash = tmp # Update sDash if a better substring is found
            else:
                if not firstTime: # If it's not the first time, break the loop
                    break
        if firstTime: # Check if it's the first time through the loop
            firstTime = False # Set the flag to false
            if 2**K > N: # Check the power of 2 of K
                print(sDash[0]*N) # Print the character N times
                sys.exit(0) # Exit the program
        else:
            step *= 2 # Double the step size
        K -= 1 # Decrement K
        S = sDash[::-1] # Update S with the best substring found

    print(S[::-1]) # Print the final reversed string S

if __name__ == "__main__":
    main()

