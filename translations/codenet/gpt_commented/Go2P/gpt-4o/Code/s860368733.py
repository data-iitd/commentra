def main():
    # Read the values of n and m from standard input
    n, m = map(int, input().split())
    
    # Create a list to hold the heights of n elements
    h = list(map(int, input().split()))
    
    # Create a set to keep track of unique elements that are involved in comparisons
    counter = set()
    
    # Loop through m comparisons
    for _ in range(m):
        # Read the indices of the two elements to compare
        a, b = map(int, input().split())
        
        # Compare the heights of the two elements
        if h[a - 1] < h[b - 1]:
            # If height of a is less than height of b, add a to the counter
            counter.add(a)
        elif h[a - 1] > h[b - 1]:
            # If height of a is greater than height of b, add b to the counter
            counter.add(b)
        else:
            # If heights are equal, add both a and b to the counter
            counter.add(a)
            counter.add(b)
    
    # Print the number of elements that were not involved in any comparisons
    print(n - len(counter))

if __name__ == "__main__":
    main()

# <END-OF-CODE>
