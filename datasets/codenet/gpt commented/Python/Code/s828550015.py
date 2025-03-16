# Read input values for x, y, a, b, and c
x, y, a, b, c = map(int, input().split())

# Read the first list of integers, sort it in descending order, and take the top x elements
p = sorted([int(i) for i in input().split()], reverse=True)[:x]

# Read the second list of integers, sort it in descending order, and take the top y elements
q = sorted([int(i) for i in input().split()], reverse=True)[:y]

# Read the third list of integers, sort it in descending order
r = sorted([int(i) for i in input().split()], reverse=True)

# Combine the top x and y elements from the first two lists and sort them
pq = sorted(p + q)

# Iterate through the minimum of x+y, a+b, and c
for i in range(min(x + y, a + b, c)):
    # If the current element in pq is less than the corresponding element in r
    if pq[i] < r[i]:
        # Replace the element in pq with the element from r
        pq[i] = r[i]

# Print the sum of the modified pq list
print(sum(pq))
