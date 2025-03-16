import sys

min_result = float('inf')  # Initializing min_result to the maximum possible float value

def util(arr, ops, idx):
    global min_result
    if idx == 3:  # Base case: when all operations are applied
        min_result = min(min_result, arr[0])  # Update min_result with the current result
        return

    # Iterating through the array to apply operations between two numbers
    for i in range(len(arr)):
        for j in range(i + 1, len(arr)):
            # Temporary list to store remaining numbers
            a = [arr[k] for k in range(len(arr)) if k != j and k != i]

            res = 0  # Variable to store the result of the operation
            if idx < 3 and ops[idx] == "+":
                res = arr[i] + arr[j]  # Applying addition
            else:
                res = arr[i] * arr[j]  # Applying multiplication

            a.append(res)  # Adding the result to the temporary list
            util(a, ops, idx + 1)  # Recursively calling util with the updated list and index

# Reading four numbers and storing them in a list
arr = list(map(int, sys.stdin.readline().split()))

# Reading three operations and storing them in a list
ops = sys.stdin.readline().split()

# Calling the recursive function to find the minimum result
util(arr, ops, 0)

# Outputting the minimum result
print(min_result)
