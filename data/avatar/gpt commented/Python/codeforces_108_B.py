def s():
    # Read an input line (not used in the logic)
    input()
    
    # Read a line of integers, split by spaces, and convert them to a list of integers
    a = list(map(int, input().split()))
    
    # Sort the list of integers in ascending order
    a.sort()
    
    # Iterate through the sorted list starting from the second element
    for i in range(1, len(a)):
        # Check if the current element is different from the previous one
        # and if it is less than double the previous element
        if a[i] != a[i - 1] and a[i] < a[i - 1] * 2:
            # If the condition is met, return 'YES'
            return 'YES'
    
    # If no such pair is found, return 'NO'
    return 'NO'

# Call the function and print the result
print(s())
