
y = int(input())  # Take an integer input for variable y
arr = [int(i) for i in input().split()]  # Take a list of integers as input and store it in arr

# Iterate through the list arr using three nested loops
for i in range(len(arr)):
    for j in range(len(arr)):
        if i == j:
            continue  # Skip if i and j are the same index
        for k in range(len(arr)):
            if arr[k] != arr[j] and arr[k] != arr[i] and arr[k] == arr[i] + arr[j]:
                # Check if arr[k] is the sum of arr[i] and arr[j] and different from both
                print(k + 1, j + 1, i + 1)  # Print the positions of arr[k], arr[j], and arr[i] (1-indexed)
                exit()  # Exit the program
print(-1)  # Print -1 if no such element is found

