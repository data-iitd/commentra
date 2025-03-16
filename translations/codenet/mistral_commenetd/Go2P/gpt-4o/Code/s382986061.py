# Initialize variables
N, K = map(int, input().split())

# Initialize a dictionary to store the frequency of each number
as_freq = {i: 0 for i in range(1, N + 1)}

# Read K queries and process them
for _ in range(K):
    d = int(input())
    # Read the numbers in the query and increment their frequency in the dictionary
    for _ in range(d):
        a = int(input())
        as_freq[a] += 1

# Initialize a variable named ans to store the answer
ans = 0

# Iterate through the dictionary and check if the frequency of any number is zero
# If yes, increment the value of ans
for v in as_freq.values():
    if v == 0:
        ans += 1

# Print the final answer
print(ans)

# End of the code
