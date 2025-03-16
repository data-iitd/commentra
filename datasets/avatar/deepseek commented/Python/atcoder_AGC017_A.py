# Read the values of N and P from input
N, P = map(int, input().split())

# Define a function to calculate the binomial coefficient
def combi(N, K):
    a = 1
    # Calculate the product part of the binomial coefficient
    for i in range(K):
        a *= N - i
    # Calculate the division part of the binomial coefficient
    for j in range(K):
        a /= j + 1
    return a

# Read a list of integers from input
ans = 0
lis = list(map(int, input().split()))

# Create a new list where each element is the remainder when divided by 2
ls = []
for a in lis:
    ls.append(a % 2)

# Count the number of 1s and 0s in the list
one = ls.count(1)
zero = ls.count(0)

# Initialize variables to store the number of patterns
pattern_a = 0
pattern_b = 0

# Calculate the number of patterns with `j` zeros using the combi function
for j in range(zero + 1):
    pattern_b += combi(zero, j)

# Initialize time to 0 for the while loop
time = 0

# Calculate the number of patterns with `time` ones, considering the parity with P
while time <= one:
    if time % 2 == P:
        pattern_a += combi(one, time)
    time += 1

# Print the result as an integer by multiplying pattern_a and pattern_b
print(int(pattern_a * pattern_b))
