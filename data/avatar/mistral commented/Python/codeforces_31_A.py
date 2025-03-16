# Take an integer input from the user
y = int(input())

# Take a list of integers as input from the user
arr = [int(i) for i in input().split()]

# Iterate through each index 'i' in the list 'arr'
for i in range(len(arr)):
    # Iterate through each index 'j' in the list 'arr' (excluding the current index 'i')
    for j in range(len(arr)):
        # Check if the current indices 'i' and 'j' are equal, if yes then skip the current iteration
        if i == j:
            continue
        # Iterate through each index 'k' in the list 'arr' (excluding the indices 'i' and 'j')
        for k in range(len(arr)):
            # Check if the current indices 'i', 'j' and 'k' satisfy the given condition
            if arr[k] != arr[j] and arr[k] != arr[i] and arr[k] == arr[i] + arr[j]:
                # If the condition is true, print the indices 'i', 'j' and 'k' and exit the function
                print(k + 1, j + 1, i + 1)
                exit()
# If no such indices are found, print -1
print(-1)