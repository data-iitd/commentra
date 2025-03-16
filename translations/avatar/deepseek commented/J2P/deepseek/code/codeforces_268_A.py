def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    # Read the number of elements
    n = int(data[0])
    
    # Initialize lists to store the elements
    h = []
    g = []
    
    # Read n pairs of integers from the standard input
    for i in range(1, n + 1):
        h.append(int(data[i]))
        g.append(int(data[i + n]))
    
    # Initialize the result variable to 0
    result = 0
    
    # Iterate through each element in list h
    for i in range(n):
        # Compare each element in list h with each element in list g
        for j in range(n):
            if h[i] == g[j]:
                # If a match is found, increment the result
                result += 1
    
    # Print the value of result
    print(result)

main()
