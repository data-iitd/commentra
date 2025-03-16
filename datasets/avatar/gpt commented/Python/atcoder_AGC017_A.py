# Read two integers N and P from input
N, P = map(int, input().split())

# Function to calculate combinations C(N, K)
def combi(N, K):
    a = 1
    # Calculate the numerator of the combination formula
    for i in range(K):
        a *= N - i
    # Calculate the denominator of the combination formula
    for j in range(K):
        a /= j + 1
    return a

# Initialize the answer variable
ans = 0

# Read a list of integers from input
lis = list(map(int, input().split()))

# Create a list to hold the parity (0 or 1) of each number
ls = []
for a in lis:
    # Append the remainder when divided by 2 (0 for even, 1 for odd)
    ls.append(a % 2)

# Count the number of 1s (odd numbers) and 0s (even numbers) in the list
one = ls.count(1)
zero = ls.count(0)

# Initialize variables to count patterns
pattern_a = 0
pattern_b = 0

# Calculate the total number of patterns for the even numbers
for j in range(zero + 1):
    pattern_b += combi(zero, j)

# Initialize a variable to track the number of odd numbers used
time = 0

# Loop through all possible counts of odd numbers used
while time <= one:
    # Check if the current count of odd numbers is congruent to P modulo 2
    if time % 2 == P:
        # If it is, add the number of combinations to pattern_a
        pattern_a += combi(one, time)
    time += 1

# Print the final result, which is the product of pattern_a and pattern_b
print(int(pattern_a * pattern_b))
