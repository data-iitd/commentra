import sys

# Read the number of elements
n = int(input().strip())

# Initialize a list to store the elements and read them from input
a = list(map(int, input().strip().split()))

# Sort the list to facilitate duplicate checking
a.sort()

# Check for duplicates in the sorted list
for i in range(n - 1):
    if a[i] == a[i + 1]:
        # If a duplicate is found, print "NO" and exit
        print("NO")
        sys.exit()

# If no duplicates are found, print "YES"
print("YES")
