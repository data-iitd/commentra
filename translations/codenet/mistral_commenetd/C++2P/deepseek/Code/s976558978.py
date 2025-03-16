import sys

# Disable the warning for the use of old-style file I/O functions like fscanf and fprintf which are deprecated in newer compilers.
if sys.platform == "_WIN32":
    sys.stdin = open("dataabc155A.txt", "r")

# Read the two integers a and b from the input file.
a = int(sys.stdin.readline().strip())
b = int(sys.stdin.readline().strip())

# If a is smaller than b, print a b times.
if a < b:
    for _ in range(b):
        print(a, end='')
    print()
# If b is smaller than a, print b a times.
else:
    for _ in range(a):
        print(b, end='')
    print()

# End of code
