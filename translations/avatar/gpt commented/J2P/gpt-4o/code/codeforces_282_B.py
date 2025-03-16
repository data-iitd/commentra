def main():
    import sys
    
    # Read the number of pairs of integers to be processed
    n = int(sys.stdin.readline().strip())
    
    # Initialize a list to store the characters representing the actions
    actions = []
    
    # Initialize sums for two different actions
    s1, s2 = 0, 0
    
    # Process each pair of integers
    for _ in range(n):
        # Read the next pair of integers
        x, y = map(int, sys.stdin.readline().strip().split())
        
        # Calculate temporary sums for the current iteration
        temp1 = s1 + x
        temp2 = s2 + y
        
        # Check if adding x to s1 keeps the difference within 500
        if abs(temp1 - s2) <= 500:
            s1 += x  # Update s1
            actions.append('A')  # Record the action 'A'
            continue
        
        # Check if adding y to s2 keeps the difference within 500
        if abs(temp2 - s1) <= 500:
            s2 += y  # Update s2
            actions.append('G')  # Record the action 'G'
            continue
        
        # If neither condition is met, print -1 and exit
        print(-1)
        return
    
    # Output the recorded actions
    print(''.join(actions))  # Convert the list to a string and print the result

if __name__ == "__main__":
    main()

# <END-OF-CODE>
