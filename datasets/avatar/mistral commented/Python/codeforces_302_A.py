# Define the number of strings n and the number of operations m
n, m = map(int, input().split())

# Calculate the number of '-' symbols in the input string
sa = input().count('-')

# Ensure the number of '-' symbols is valid
sa = min([n - sa, sa])

# Initialize an empty list 'ss' to store the results of each operation
ss = []

# Perform each operation as described in the problem statement
for _ in range(m):
    # Read two integers a and b from the input
    a, b = map(int, input().split())

    # Calculate the difference between b and a
    b -= a

    # Check if the difference is valid based on the number of '-' symbols
    if (b % 2 == 0 or b > sa << 1):
        # If the difference is valid, add '1' to the result list 'ss'
        ss.append('1\n')
    # If the difference is not valid, add '0' to the result list 'ss'
    else:
        ss.append('0\n')

# Print the final result by joining all the strings in the 'ss' list with an empty string as separator
print("".join(ss))