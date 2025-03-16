import sys

# Read two integers N and K from input
N, K = map(int, input().split())

# Read a list of integers from input
lst = list(map(int, input().split()))

# Initialize lists to hold positive and negative numbers
lst_p = []
lst_m = []

# Iterate through the list to categorize numbers
for i in range(N):
    # Decrease K for each zero encountered
    if lst[i] == 0:
        K -= 1
    # Add positive numbers to lst_p
    if lst[i] > 0:
        lst_p += [lst[i]]
    # Add negative numbers to lst_m
    elif lst[i] < 0:
        lst_m += [lst[i]]

# Initialize variables to track the last indices of positive and negative lists
p = 0
m = 0
x, y = 0, len(lst_m) - 1
lastx = len(lst_p)
lasty = len(lst_m)

# Define a function to check the minimum value based on K
def check(k):
    ans = 10 ** 9  # Initialize answer with a large number
    # Iterate through possible counts of positive numbers used
    for j in range(0, k + 1):
        # Check if the current count of positives and negatives is valid
        if j > lastx or k - j > lasty:
            pass  # Skip invalid combinations
        else:
            # Determine the maximum positive number used
            if j == 0:
                p = 0  # No positive numbers used
            else:
                p = lst_p[j - 1]  # Get the largest positive number used
            
            # Determine the maximum negative number used
            if k - j == 0:
                m = 0  # No negative numbers used
            else:
                m = lst_m[lasty - (k - j)]  # Get the largest negative number used
            
            # Calculate the minimum value based on the current combination
            ans = min(ans, 2 * p + abs(m), p + 2 * abs(m))
    
    return ans  # Return the minimum value found

# Print the result of the check function with K
print(check(K))
