# Importing random module for generating random numbers if required
import random

# Taking input from user and converting it into a list of integers
input_ = input()
A = [ int(i) for i in input_.split() ]

# Adding the first element of the list to the beginning of the list
# to make the first index 0 based instead of 1 based
A = [A[0]] + [j for i, j in zip(A, A[1:]) if i >= j]

# Assigning the length of the list to a variable for easier reference
N = len(A)

# Defining a helper function to find the index of the last occurrence of an element
# in a list, and the index and value of the previous occurrence
def cut(array, index):
    # Base case: if index is less than 1, return an empty list
    if index < 1:
        return []

    # Base case: if index is less than or equal to the first element in the array
    if index <= array[0][0]:
        return [(index, array[0][1])]

    # Iterating through the array from the end to the beginning
    for _ in range(len(array) - 1, 0, -1):
        # If the previous element is smaller than the index, return the sublist up to that index
        if array[_ - 1][0] < index:
            return array[:_] + [(index, array[_][1])]

# Defining a helper function to check if it's possible to add a certain number of elements
# to the list while maintaining the condition that the previous element is smaller than the current one
def is_possible(K):
    # Initializing an empty list to store the indices and values of the elements in the list
    dp = [(A[0], 0)]

    # Iterating through the list starting from the second element
    for a in A[1:]:
        # If the current element is smaller than the last element in the dp list,
        # we need to cut the list at the previous index and add the current element
        if a <= dp[-1][0]:
            dp = cut(dp, a)

        # Adding the current element to the dp list
        dp += [(a, 0)]

        # Initializing a flag to check if we need to add an element to the dp list
        is_added = False

        # Iterating through the dp list from the end to the beginning
        for j in range(len(dp) - 1, -1, -1):
            # If the previous element has a smaller value and enough space to add the current element,
            # we need to cut the list at the previous index and add the current element
            if dp[j][1] < K - 1:
                dp = cut(dp, dp[j][0] - 1) + [(dp[j][0], dp[j][1] + 1)]

                # Checking if the last element in the dp list is smaller than the current element
                if dp[-1][0] < a:
                    dp += [(a, 0)]
                    is_added = True
                    break

        # If we didn't add an element to the dp list, the current number can't be added
        if not is_added:
            return False

# Defining a helper function to find the binary index of a number in the list
def bis(x, y):
    # Base case: if y is one more than x, return y
    if y == x + 1:
        return y

    # Recursively finding the binary index of x and y using the is_possible function
    if is_possible((x + y) // 2):
        return bis(x, (x + y) // 2)

    # If is_possible returns False for (x + y) // 2 and y, return the binary index of y
    else:
        return bis((x + y) // 2, y)

# Printing the result of the binary index function
print(bis(0, N))