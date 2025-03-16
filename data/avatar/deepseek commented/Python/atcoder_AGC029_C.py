
import random

# Taking input from the user and processing it to create a list of integers
input()
A = [int(_) for _ in input().split()]

# Modifying the list A to include only elements where the previous element is greater than or equal to the current element
A = [A[0]] + [j for i, j in zip(A, A[1:]) if i >= j]

# Storing the length of the modified list A in N
N = len(A)

# Function to cut a list of tuples based on a given index
def cut(array, index):
    if index < 1:
        return []
    if index <= array[0][0]:
        return [(index, array[0][1])]
    for _ in range(len(array) - 1, 0, -1):
        if array[_ - 1][0] < index:
            return array[:_] + [(index, array[_][1])]

# Function to check if a given value of K is possible by modifying the list dp
def is_possible(K):
    dp = [(A[0], 0)]
    for a in A[1:]:
        if a <= dp[-1][0]:
            dp = cut(dp, a)
        else:
            dp += [(a, 0)]
        is_added = False
        for j in range(len(dp) - 1, -1, -1):
            if dp[j][1] < K - 1:
                dp = cut(dp, dp[j][0] - 1) + [(dp[j][0], dp[j][1] + 1)]
                if dp[-1][0] < a:
                    dp += [(a, 0)]
                is_added = True
                break
        if not is_added:
            return False
    return True

# Function to perform a binary search to find the maximum possible value of K
def bis(x, y):
    if y == x + 1:
        return y
    elif is_possible((x + y) // 2):
        return bis(x, (x + y) // 2)
    else:
        return bis((x + y) // 2, y)

# Printing the result of the binary search
print(bis(0, N))