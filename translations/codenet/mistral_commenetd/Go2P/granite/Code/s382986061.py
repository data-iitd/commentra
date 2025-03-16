
# Initialize variables
N, K = map(int, input().split())
d = 0
a = 0

# Initialize an associative array (map) named as to store the frequency of each number
as = {}

# Initialize all elements of the map with zero frequency
for i in range(1, N+1):
    as[i] = 0

# Read K queries and process them
for i in range(K):
    # Read the length of the query
    d = int(input())

    # Read the numbers in the query and increment their frequency in the map
    for j in range(d):
        a = int(input())
        as[a] += 1

# Initialize a variable named ans to store the answer
ans = 0

# Iterate through the map and check if the frequency of any number is zero
# If yes, increment the value of ans
for _, v in as.items():
    if v == 0:
        ans += 1

# Print the final answer
print(ans)

# End of the code

