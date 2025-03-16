def main():
    # Read the number of required items (n) and the number of available items (m)
    n, m = map(int, input().split())
    
    # Read the required items from the input and store them in the req list
    req = list(map(int, input().split()))
    
    # Read the available items from the input and store them in the pre list
    pre = list(map(int, input().split()))
    
    # Initialize pointers for the required items (i) and available items (j)
    i = n - 1
    j = m - 1
    
    # Variable to count how many required items can be satisfied
    ans = 0
    
    # Compare the required items with the available items from the end of both lists
    while i >= 0 and j >= 0:
        # If the current required item is greater than the current available item
        if req[i] > pre[j]:
            # Increment the count of satisfied items
            ans += 1
        else:
            # Move to the next available item if the current one cannot satisfy the requirement
            j -= 1
        # Move to the next required item
        i -= 1
    
    # Print the total number of satisfied items plus the remaining unsatisfied required items
    print(ans + i + 1)

if __name__ == "__main__":
    main()
