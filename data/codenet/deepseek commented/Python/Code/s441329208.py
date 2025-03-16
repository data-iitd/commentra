import sys
read = sys.stdin.read
readline = sys.stdin.readline
readlines = sys.stdin.readlines
# Set the recursion limit to prevent stack overflow for deep recursion
sys.setrecursionlimit(10 ** 7)

# Read the first line of input from stdin, strip any trailing whitespace, and sort it
s = sorted(readline().rstrip())

# Read the second line of input from stdin, strip any trailing whitespace, and sort it in descending order
t = sorted(readline().rstrip())[::-1]

# Compare the two sorted lines lexicographically and print "Yes" if the first is less than the second, otherwise print "No"
print("Yes" if s < t else "No")
