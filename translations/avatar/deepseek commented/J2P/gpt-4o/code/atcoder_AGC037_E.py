import sys

def main():
    sc = sys.stdin.read
    data = sc().split()
    
    N = int(data[0])  # Read the integer N
    K = int(data[1])  # Read the integer K
    S = data[2]       # Read the string S
    first_time = True # Initialize a flag to check if it's the first time through the loop
    step = 1          # Initialize the step size

    # Main loop to manipulate the string based on the value of K
    while K > 0:
        T = S[::-1]  # Reverse the string S
        revU = (S + T)[::-1]  # Concatenate S with its reverse and reverse it
        sDash = S      # Initialize sDash with the original string S

        # Iterate over the reversed concatenated string to find the best substring
        for i in range(N, -1, -step):
            tmp = revU[i:i + N]  # Get a substring of length N
            if sDash > tmp:      # Compare lexicographically
                sDash = tmp      # Update sDash if a better substring is found
            else:
                if not first_time:  # If it's not the first time, break the loop
                    break

        # Check if it's the first time through the loop
        if first_time:
            first_time = False  # Set the flag to false
            if 2 ** K > N:      # Check the power of 2 of K
                c = sDash[0]    # Get the first character of sDash
                print(c * N)    # Print the character N times
                return           # Exit the program
        else:
            step *= 2           # Double the step size
        K -= 1                  # Decrement K
        S = sDash               # Update S with the best substring found
        S = S[::-1]            # Reverse S

    print(S[::-1])            # Print the final reversed string S

if __name__ == "__main__":
    main()

# <END-OF-CODE>
