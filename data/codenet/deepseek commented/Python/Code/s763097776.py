
n = int(input())  # Read the number of elements in the list
p = [int(x) for x in input().split()]  # Read the list of integers
p_copy = p[:]  # Create a copy of the list p

# Sort the list p
p.sort()

# Initialize a counter to keep track of the number of positions where the elements differ
count = 0

# Iterate through the list p and compare each element with the corresponding element in p_copy
for i in range(n):
    if p[i] != p_copy[i]:
        count += 1

# Check if the count is 0 or 2, and print "YES" if true, otherwise print "NO"
if count == 0 or count == 2:
    print("YES")
else:
    print("NO")