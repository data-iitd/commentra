import sys

def main():
    # Read the input from stdin
    N, K = map(int, sys.stdin.readline().split())
    S = sys.stdin.readline().strip()
    
    # Flag to check if we are processing the first iteration
    firstTime = True
    # Variable to control the step size for substring extraction
    step = 1
    
    # Loop until K operations are performed
    while K > 0:
        # Create a reversed copy of the current string S
        T = S[::-1]
        
        # Create a new string that combines S and its reverse, then reverse it
        revU = S + T
        revU = revU[::-1]
        
        # Initialize a variable to keep track of the best string found so far
        sDash = S
        
        # Iterate through the string revU to find the lexicographically smallest substring
        for i in range(N, 0, -step):
            # Extract a substring from revU
            tmp = revU[i:i + N]
            
            # Compare and update sDash if a smaller substring is found
            if sDash > tmp:
                sDash = tmp
            else:
                # If we are not in the first iteration, break the loop
                if not firstTime:
                    break
        
        # If this is the first iteration, check if we can print a uniform string
        if firstTime:
            firstTime = False
            # If 2^K is greater than N, print the first character of sDash N times
            if 2 ** K > N:
                c = sDash[0]
                for i in range(N):
                    print(c, end='')
                print()
                sys.exit(0)
        
        # Increase the step size for the next iteration
        step += step
        
        # Decrement K and update S for the next operation
        K -= 1
        S = sDash[::-1]
    
    # Print the final result after all operations
    print(S)

if __name__ == "__main__":
    main()

