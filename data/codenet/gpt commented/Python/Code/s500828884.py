# Read input values for n, a, and b from the user
n, a, b = map(int, input().split())

# Calculate the minimum cost between 'n * a' (cost of buying n items at price a each) 
# and 'b' (a fixed cost)
result = min(n * a, b)

# Print the result which is the minimum cost
print(result)
