# Read a line of input, split it into components, and convert them to integers
candy = sorted(map(int, input().split()))

# Check if the sum of the two smallest integers equals the largest integer
# If true, print "Yes", otherwise print "No"
print("Yes" if candy[0] + candy[1] == candy[2] else "No")
