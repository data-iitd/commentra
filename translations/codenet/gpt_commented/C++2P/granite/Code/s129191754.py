
# Synchronize input/output for faster performance
import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

# Read the number of elements
n = int(input())

# Initialize a list to store the elements and read them from input
a = list(map(int, input().split()))

# Sort the list to facilitate duplicate checking
a.sort()

# Check for duplicates in the sorted list
for i in range(n - 1):
    if a[i] == a[i + 1]:
        # If a duplicate is found, print "NO" and exit
        print("NO")
        exit()

# If no duplicates are found, print "YES"
print("YES")

