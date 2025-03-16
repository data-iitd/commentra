def main():
    import sys
    
    # Read the integer N (length of the string) and K (number of operations)
    N = int(input())
    K = int(input())
    
    # Read the initial string and create a list for manipulation
    S = list(input().strip())
    
    # Flag to check if we are processing the first iteration
    first_time = True
    # Variable to control the step size for substring extraction
    step = 1
    
    # Loop until K operations are performed
    while K > 0:
        # Create a reversed copy of the current string S
        T = S[::-1]
        
        # Create a new list that combines S and its reverse, then reverse it
        revU = (S + T)[::-1]
        
        # Initialize a variable to keep track of the best string found so far
        s_dash = ''.join(S)
        
        # Iterate through the string revU to find the lexicographically smallest substring
        for i in range(N, -1, -step):
            # Extract a substring from revU
            tmp = ''.join(revU[i:i + N])
            
            # Compare and update s_dash if a smaller substring is found
            if s_dash > tmp:
                s_dash = tmp
            else:
                # If we are not in the first iteration, break the loop
                if not first_time:
                    break
        
        # If this is the first iteration, check if we can print a uniform string
        if first_time:
            first_time = False
            # If 2^K is greater than N, print the first character of s_dash N times
            if 2 ** K > N:
                c = s_dash[0]
                print(c * N)
                return
        
        # Increase the step size for the next iteration
        step += step
        
        # Decrement K and update S for the next operation
        K -= 1
        S = list(s_dash)
        S.reverse()
    
    # Print the final result after all operations
    print(''.join(S[::-1]))

if __name__ == "__main__":
    main()

# <END-OF-CODE>
