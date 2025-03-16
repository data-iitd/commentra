import sys

def main():
    # Read the number of pairs of integers to be processed
    n = int(input().strip())
    
    # Initialize an array to store the characters representing the actions
    ch = [None] * n
    
    # Initialize sums for two different actions
    s1 = 0
    s2 = 0
    
    # Process each pair of integers
    for i in range(n):
        # Read the next pair of integers
        x, y = map(int, input().strip().split())
        
        # Calculate temporary sums for the current iteration
        temp1 = s1 + x
        temp2 = s2 + y
        
        # Check if adding x to s1 keeps the difference within 500
        if abs(temp1 - s2) <= 500:
            s1 += x  # Update s1
            ch[i] = 'A'  # Record the action 'A'
            continue  # Move to the next iteration
        
        # Check if adding y to s2 keeps the difference within 500
        if abs(temp2 - s1) <= 500:
            s2 += y  # Update s2
            ch[i] = 'G'  # Record the action 'G'
            continue  # Move to the next iteration
        
        # If neither condition is met, set flag to indicate failure
        print(-1)
        return
    
    # Convert the character array to a string and print the result
    ans = ''.join(ch)
    print(ans)

if __name__ == "__main__":
    main()
