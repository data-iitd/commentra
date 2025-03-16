# Declare variables for the number of elements (n), number of inputs (m), and the starting point (x)
n, m, x = map(int, input().split())
# Initialize a list to keep track of the presence of numbers (size 105 to accommodate possible values)
a = [0] * 105

# Read m numbers from input and mark their presence in the list 'a'
for _ in range(m):
    temp = int(input())
    a[temp] = 1

# Initialize counters for the number of present elements to the right (ansr) and left (ansl) of x
ansl = 0
ansr = 0

# Count how many numbers are present from x to n (right side)
for i in range(x, n + 1):
    ansr += a[i]  # Increment ansr if a[i] is 1 (indicating presence)

# Count how many numbers are present from x to 0 (left side)
for i in range(x, -1, -1):
    ansl += a[i]  # Increment ansl if a[i] is 1 (indicating presence)

# Output the minimum of the counts from both sides
print(min(ansl, ansr))

# <END-OF-CODE>
