import sys

def main():
    # Read the integer N
    N = int(input().strip())
    # Read the integer K
    K = int(input().strip())
    # Read the string S and wrap it in a StringBuilder
    S = input().strip()
    first_time = True
    step = 1

    # Main loop to manipulate the string based on the value of K
    while K > 0:
        T = S[::-1]  # Reverse the copy
        revU = S + T  # Concatenate S with its reverse
        revU = revU[::-1]  # Reverse the concatenated string
        s_dash = S  # Initialize s_dash with the original string S

        # Iterate over the reversed concatenated string to find the best substring
        for i in range(N, -1, -step):
            tmp = revU[i:i+N]  # Get a substring of length N
            if s_dash > tmp:  # Compare lexicographically
                s_dash = tmp  # Update s_dash if a better substring is found
            else:
                if not first_time:  # If it's not the first time, break the loop
                    break

        # Check if it's the first time through the loop
        if first_time:
            first_time = False  # Set the flag to false
            if 2**K > N:  # Check the power of 2 of K
                c = s_dash[0]  # Get the first character of s_dash
                for _ in range(N):  # Print the character N times
                    print(c, end='')
                print()  # Print a newline
                sys.exit(0)  # Exit the program

        # Double the step size
        step += step
        K -= 1  # Decrement K
        S = s_dash  # Update S with the best substring found

    # Print the final reversed string S
    print(S[::-1])

if __name__ == "__main__":
    main()
