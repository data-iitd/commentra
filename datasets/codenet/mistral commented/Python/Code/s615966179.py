
n, a, b = map(int, input().split())
# Define variables n, a, and b as integers

ans = n // (a + b)
# Calculate the quotient of n divided by the sum of a and b
# This quotient represents the number of complete sums of a and b that can be formed from n

r = min(n % (a + b), a)
# Calculate the remainder of n when divided by the sum of a and b
# This remainder represents the number of leftover elements that cannot be formed into a complete sum of a and b
# Assign the minimum of this remainder and a to the variable r

ans += r
# Add the quotient ans and the remainder r to obtain the final answer

print(ans)
# Print the final answer