def main():
    # Read input values: n (number of elements) and x (a multiplier)
    n, x = map(int, input().split())
    
    # Read the list of integers 'a' from input
    a = list(map(int, input().split()))
    
    # Initialize a 2D list 'b' with None values to store minimum values
    b = [[None for _ in [0] * n] for _ in [0] * n]
    
    # Fill the 2D list 'b' with minimum values from 'a'
    for i in range(n):
        m = a[i]  # Start with the current element
        for j in range(n):
            k = i - j  # Calculate the index to wrap around
            if k < 0:
                k += n  # Wrap around if index is negative
            m = min(m, a[k])  # Update m to be the minimum value found
            b[j][i] = m  # Store the minimum value in the 2D list 'b'
    
    # Initialize a large value for comparison
    m = 10 ** 15
    
    # Calculate the minimum sum of elements in each row of 'b' plus the weighted index
    for i, j in enumerate(b):
        m = min(m, sum(j) + x * i)  # Update m with the minimum found
    
    # Print the final minimum value
    print(m)

# Call the main function to execute the program
main()
