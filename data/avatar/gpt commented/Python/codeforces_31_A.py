# Read an integer input which represents the size of the array
y = int(input())

# Read a line of input, split it into individual strings, convert them to integers, and store them in a list
arr = [int(i) for i in input().split()]

# Iterate over each element in the array using index i
for i in range(len(arr)):
    # Iterate over each element in the array using index j
    for j in range(len(arr)):
        # Skip the iteration if both indices are the same
        if i == j:
            continue
        # Iterate over each element in the array using index k
        for k in range(len(arr)):
            # Check if the current element at index k is different from elements at indices i and j,
            # and if it is equal to the sum of the elements at indices i and j
            if arr[k] != arr[j] and arr[k] != arr[i] and arr[k] == arr[i] + arr[j]:
                # Print the 1-based indices of the elements that satisfy the condition
                print(k + 1, j + 1, i + 1)
                # Exit the program after finding the first valid triplet
                exit()

# If no valid triplet is found, print -1
print(-1)
