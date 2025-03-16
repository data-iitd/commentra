import sys

# Function to read an integer from input
def read():
    x = 0
    f = 1
    ch = sys.stdin.read(1)
    while ch < '0' or ch > '9':
        if ch == '-':
            f = -1
        ch = sys.stdin.read(1)
    while ch >= '0' and ch <= '9':
        x = x * 10 + int(ch)
        ch = sys.stdin.read(1)
    return x * f

# Function to write an integer to output
def write(x):
    if x < 0:
        sys.stdout.write('-')
        x = -x
    if x >= 10:
        write(x // 10)
    sys.stdout.write(chr(x % 10 + ord('0')))

# Function to write an integer followed by a newline
def writeln(x):
    write(x)
    sys.stdout.write('\n')

N = 200010
a = [0] * N
q = [0] * N
n = 0
tot = 0

# Read the number of elements
n = read()
# Read the elements into the array a
a = [read() for _ in range(n)]
# Sort the array in non-decreasing order
a.sort()

# Identify duplicates and store them in array q
i = 0
while i < n:
    if a[i] == a[i + 1]:
        q[tot] = a[i]
        tot += 1
        i += 2
    else:
        i += 1

# Output the product of the last two duplicates found
writeln(q[tot - 1] * q[tot - 2])

# End-of-code comment
