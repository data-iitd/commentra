import sys

# Read the number of elements in the list
n = int(input().strip())

# Read the elements of the list
a = list(map(int, input().strip().split()))

# Sort the list in ascending order
a.sort()

# Check if there are any consecutive elements in the sorted list
for i in range(n - 1):
    # If there are consecutive elements, print "NO" and exit the program
    if a[i] == a[i + 1]:
        print("NO")
        sys.exit()

# If no consecutive elements were found, print "YES"
print("YES")
