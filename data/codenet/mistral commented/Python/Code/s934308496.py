# User inputs n and x, and convert them to integers
n, x = map(int, input().split())

# Initialize an empty list m with a length of n
m = []
# m.resize(n)  # This line is not needed

# Read n integers from user input and fill the list m
m = [int(input()) for _ in range(n)]

# Sort the list m in ascending order
m.sort()

# Calculate the answer and print it
print(n + (x - sum(m)) // m[0])