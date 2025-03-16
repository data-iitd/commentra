
# Declare variables for the number of elements (n), number of inputs (m), and the starting point (x)
n, m, x = map(int, input().split())

# Initialize an array to keep track of the presence of numbers (size 105 to accommodate possible values)
a = [0] * 105

# Read m numbers from input and mark their presence in the array 'a'
for i in range(m):
    temp = int(input())
    a[temp] = 1

# Initialize counters for the number of present elements to the right (ansr) and left (ansl) of x
ansl = 0
ansr = 0
i = x

# Count how many numbers are present from x to n (right side)
while i <= n:
    ansr += a[i]
    i += 1

# Count how many numbers are present from x to 0 (left side)
i = x
while i >= 0:
    ansl += a[i]
    i -= 1

# Output the minimum of the counts from both sides
print(min(ansl, ansr))

# 