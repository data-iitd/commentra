# Importing the sys module for handling system-specific exceptions
import sys

# Taking the number of elements N and the number of queries K as input
N, K = map(int, input().split())

# Creating an empty list to store positive numbers and another empty list to store negative numbers
lst = list(map(int, input().split()))
lst_p = []
lst_m = []

# Iterating through the list to find positive and negative numbers
for i in range(N):
    # If the number is zero, decrement the number of queries K
    if lst[i] == 0:
        K -= 1
    # If the number is positive, add it to the list of positive numbers
    elif lst[i] > 0:
        lst_p.append(lst[i])
    # If the number is negative, add it to the list of negative numbers
    elif lst[i] < 0:
        lst_m.append(lst[i])

# Initializing variables p and m to 0 and setting the initial values of x and y
p, m, x, y = 0, 0, 0, len(lst_m) - 1
lastx = len(lst_p)
lasty = len(lst_m)

# Function to check the minimum number of moves required to make the sum of the first k elements equal to or less than 0
def check(k):
    # Initializing the answer as a large number
    ans = 10 ** 9

    # Iterating through all possible combinations of taking elements from positive and negative lists
    for j in range(k + 1):
        # If the index j is greater than the length of the list of positive numbers or if the number of elements to be taken from negative list is greater than the number of negative elements, then skip this iteration
        if j > lastx or k - j > lasty:
            continue

        # If j is 0, then p is initialized to 0
        if j == 0:
            p = 0
        # If j is not 0, then p is the last element of the list of positive numbers
        else:
            p = lst_p[j - 1]

        # If k - j is 0, then m is initialized to 0
        if k - j == 0:
            m = 0
        # If k - j is not 0, then m is the last element of the list of negative numbers
        else:
            m = lst_m[lasty - (k - j)]

        # Updating the answer with the minimum of the current answer and the sum of the absolute difference of p and m and the sum of p and m
        ans = min(ans, 2 * p + abs(m), p + 2 * abs(m))

    # Returning the answer
    return ans

# Printing the minimum number of moves required to make the sum of the first K elements equal to or less than 0
print(check(K))
