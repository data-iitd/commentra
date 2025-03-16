
# Define a constant for the value of PI
PI = 3.14159265358979

# Define a type alias for long long
ll = int

# Define a function to calculate the number of pairs within a group
def pairs(n):
    return n * (n - 1) / 2

# Declare variables to hold the number of groups
n, m = map(int, input().split())

# Calculate the number of pairs within group n
# The formula n*(n-1)/2 gives the number of ways to choose 2 from n
ans = pairs(n)

# Calculate the number of pairs within group m
# Similarly, m*(m-1)/2 gives the number of ways to choose 2 from m
ans += pairs(m)

# Output the total number of pairs
print(ans)

