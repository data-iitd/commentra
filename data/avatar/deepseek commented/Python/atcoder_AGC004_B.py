def main():
    # Read the values of n and x
    n, x = map(int, input().split())
    
    # Read the list of integers a
    a = list(map(int, input().split()))
    
    # Initialize a 2D list b with None values
    # b[j][i] will store the minimum value in the circular array from i to j
    b = [[None for _ in range(n)] for _ in range(n)]
    
    # Calculate the minimum value in a circular array for each starting position i and ending position j
    for i in range(n):
        m = a[i]  # Initialize m with the current element
        for j in range(n):
            k = i - j  # Calculate the index in the circular array
            if k < 0:
                k += n  # Adjust k if it is negative
            m = min(m, a[k])  # Update m with the minimum value in the circular array
            b[j][i] = m  # Store the minimum value in b
    
    # Find the minimum sum of each row in b plus x times the row index
    m = 10 ** 15
    for i, j in enumerate(b):
        m = min(m, sum(j) + x * i)
    
    # Print the minimum value found
    print(m)

main()
