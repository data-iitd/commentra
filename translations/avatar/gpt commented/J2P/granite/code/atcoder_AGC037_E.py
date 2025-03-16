
import sys

def main():
    # Read the integer N (length of the string) and K (number of operations)
    N, K = map(int, input().split())
    
    # Read the initial string and create a list for manipulation
    S = list(input())
    
    # Flag to check if we are processing the first iteration
    first_time = True
    # Variable to control the step size for substring extraction
    step = 1
    
    # Loop until K operations are performed
    while K > 0:
        # Create a reversed copy of the current string S
        T = S[::-1]
        
        # Create a new list that combines S and its reverse, then reverse it
        rev_U = T + S
        
        # Initialize a variable to keep track of the best string found so far
        s_dash = S
        
        # Iterate through the list rev_U to find the lexicographically smallest substring
        for i in range(N, -1, -step):
            # Extract a substring from rev_U
            tmp = rev_U[i:i+N]
            
            # Compare and update s_dash if a smaller substring is found
            if ''.join(s_dash) > ''.join(tmp):
                s_dash = tmp
            else:
                # If we are not in the first iteration, break the loop
                if not first_time:
                    break
        
        # If this is the first iteration, check if we can print a uniform string
        if first_time:
            first_time = False
            # If 2^K is greater than N, print the first character of s_dash N times
            if 2**K > N:
                c = s_dash[0]
                print(c*N)
                sys.exit(0)
        else:
            # Increase the step size for the next iteration
            step *= 2
        
        # Decrement K and update S for the next operation
        K -= 1
        S = s_dash[::-1]
    
    # Print the final result after all operations
    print(''.join(S))

if __name__ == "__main__":
    main()

