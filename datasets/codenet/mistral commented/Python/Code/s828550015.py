# Define variables x, y, a, b, and c as integers using map and input().split()
x, y, a, b, c = map(int, input().split())

# Create list p by sorting the list of integers obtained from input in reverse order and selecting the first x elements
p = sorted([int(i) for i in input().split()], reverse=True)[:x]

# Create list q by sorting the list of integers obtained from input in reverse order and selecting the first y elements
q = sorted([int(i) for i in input().split()], reverse=True)[:y]

# Create list r by sorting the list of integers obtained from input in reverse order
r = sorted([int(i) for i in input().split()], reverse=True)

# Merge p and q into a single list pq by sorting their union in reverse order
pq = sorted(p + q, reverse=True)

# Iterate over the minimum of x+y, a+b, and c elements in pq and r. If the element in pq is less than the corresponding element in r, update the element in pq
for i in range(min(x+y, a+b, c)):
    if pq[i] < r[i]:
        pq[i] = r[i]

# Print the sum of the elements in pq
print(sum(pq))