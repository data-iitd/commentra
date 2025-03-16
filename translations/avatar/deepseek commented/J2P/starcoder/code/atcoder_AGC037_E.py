import sys; # Import the sys module for input

def main():
    N = int(sys.stdin.readline()); # Read the integer N
    K = int(sys.stdin.readline()); # Read the integer K
    S = sys.stdin.readline().strip(); # Read the string S and strip the newline character
    firstTime = True; # Initialize a flag to check if it's the first time through the loop
    step = 1; # Initialize the step size

    # Main loop to manipulate the string based on the value of K
    while K > 0:
        T = S[::-1]; # Reverse the copy
        revU = S + T; # Concatenate S with its reverse
        revU = revU[::-1]; # Reverse the concatenated string
        sDash = S; # Initialize sDash with the original string S

        # Iterate over the reversed concatenated string to find the best substring
        for i in range(N, -1, -step):
            tmp = revU[i:i + N]; # Get a substring of length N
            if sDash > tmp: # Compare lexicographically
                sDash = tmp; # Update sDash if a better substring is found
            else:
                if not firstTime: # If it's not the first time, break the loop
                    break;

        # Check if it's the first time through the loop
        if firstTime:
            firstTime = False; # Set the flag to false
            if pow(2, K) > N: # Check the power of 2 of K
                c = sDash[0]; # Get the first character of sDash
                for i in range(N): # Print the character N times
                    print(c, end = "");
                print(); # Print a newline
                sys.exit(0); # Exit the program
        else:
            step += step; # Double the step size
        K -= 1; # Decrement K
        S = sDash; # Update S with the best substring found
        S = S[::-1]; # Reverse S
    print(S[::-1]); # Print the final reversed string S

if __name__ == "__main__":
    main(); # Call the main function

