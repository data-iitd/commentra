
# Read the number of elements
n = int(input())

# Initialize a vector to store the elements and read them from input
a = [int(input()) for i in range(n)]

# Sort the vector to facilitate duplicate checking
a.sort()

# Check for duplicates in the sorted vector
for i in range(n - 1):
    if a[i] == a[i + 1]:
        # If a duplicate is found, print "NO" and exit
        print("NO")
        exit(0)

# If no duplicates are found, print "YES"
print("YES")

