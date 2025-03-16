# Read an integer input for the number of elements
n = int(input())

# Read a list of integers from input and store it in p
p = [int(x) for x in input().split()]

# Create a copy of the original list p for later comparison
p_copy = p[:]

# Sort the list p to compare with the original order
p.sort()

# Initialize a counter to track the number of mismatches between sorted and original lists
count = 0

# Loop through each element to compare the sorted list with the original list
for i in range(n):
    # If the elements at the same index are different, increment the count
    if p[i] != p_copy[i]:
        count += 1

# Check if the count of mismatches is 0 or 2
if count == 0 or count == 2:
    # If there are no mismatches or exactly two mismatches, print "YES"
    print("YES")
else:
    # If there are an odd number of mismatches, print "NO"
    print("NO")
