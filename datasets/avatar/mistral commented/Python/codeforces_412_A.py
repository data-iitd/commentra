# Read the number of elements `n` and the number of queries `k` from the standard input
n, k = map(int, input().split())

# Read a single string `v` from the standard input
v = input()

# Initialize a list `d` with two elements: "LEFT" and "RIGHT"
d = ["LEFT", "RIGHT"]

# Determine the direction based on the difference between `k` and `n-k`
f = k - 1 < n - k

# Determine the number of elements to be appended to the list `a`
m = min(k - 1, n - k)

# Initialize an empty list `a`
a = []

# Append "LEFT" or "RIGHT" to the list `a` based on the value of `f`
for i in range(0, m):
    a.append(d[not f])

# Iterate through the string `v` with a step of 2 times the value of `f`
for i in range(0, len(v), 2 * f):
    # Append "PRINT <character>" and the corresponding direction to the list `a`
    a.append(f"PRINT {v[i]}")
    a.append(d[f])

# Print all the elements of the list `a`, except the last one, separated by newline characters
print(*a[:-1], sep="\n")