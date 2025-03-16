#######
# Code
#######

# Read the input values N and P from the user
N, P = map(int, input().split())

# Define a function to calculate the number of combinations of choosing K items from a set of N items
def combi(N, K):
    # Initialize the combination value to 1
    a = 1
    
    # Calculate the combination value by multiplying the number of choices from the set (N) to the current index (i)
    # and then dividing it by the current index (i+1) to account for the repetition of choices
    for i in range(K):
        a *= (N - i)
        a /= (i + 1)
    
    # Return the calculated combination value
    return a

# Initialize the answer variable to 0
ans = 0

# Read the input values from the user and store them in a list
lis = list(map(int, input().split()))

# Initialize an empty list to store the remainder of each input value when divided by 2
ls = []

# Iterate through each value in the list and append its remainder to the list
for a in lis:
    ls.append(a % 2)

# Calculate the number of 1's and 0's in the list
one = ls.count(1)
zero = ls.count(0)

# Initialize two variables to store the pattern values
pattern_a = 0
pattern_b = 0

# Calculate the value of pattern_b by summing up the combinations of choosing 0's from the list
for j in range(zero + 1):
    pattern_b += combi(zero, j)

# Calculate the value of pattern_a by summing up the combinations of choosing numbers from the list based on the value of P
time = 0
while time <= one:
    # Check if the current index (time) is a multiple of P
    if time % P == 0:
        # If yes, add the combination value to pattern_a
        pattern_a += combi(one, time)
    
    # Increment the index for the next combination
    time += 1

# Print the final answer as an integer
print(int(pattern_a * pattern_b))
