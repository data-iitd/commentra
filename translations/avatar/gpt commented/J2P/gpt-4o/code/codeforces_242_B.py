# Define a constant for infinity
INF = int(1e9) + 5

def main():
    # Create a list to store the pairs
    a = []
    b = []
    
    # Read the number of pairs
    n = int(input())
    
    # Initialize left to infinity and right to zero
    left = INF
    right = 0
    
    # Read the pairs and determine the minimum and maximum values
    for i in range(n):
        a_i, b_i = map(int, input().split())
        a.append(a_i)  # Read the first element of the pair
        b.append(b_i)  # Read the second element of the pair
        
        # Update left to the minimum value found in a
        left = min(left, a[i])
        # Update right to the maximum value found in b
        right = max(right, b[i])
    
    # Check for a pair that matches the left and right bounds
    for i in range(n):
        # If the current pair matches the min and max values
        if left == a[i] and right == b[i]:
            # Print the index (1-based) and exit
            print(i + 1)
            return
    
    # If no matching pair is found, print -1
    print(-1)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
