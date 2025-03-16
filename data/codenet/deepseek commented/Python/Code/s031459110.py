
N = int(input())  # Read the integer input N
c = input()       # Read the string input c

# Count the number of "W"s and "R"s in the string c
num_w = c.count("W")
num_r = N - num_w

# Construct a string comp which is a concatenation of "R" repeated num_r times and "W" repeated num_w times
comp = "R"*num_r + "W"*num_w

# Initialize a variable ans to 0
ans = 0

# Iterate over the first num_r elements of c and compare each element with the corresponding element in comp
for i in range(num_r):
    if c[i] != comp[i]:
        ans += 1

# Update ans to be the minimum of num_w, num_r, and the current value of ans
ans = min(num_w, num_r, ans)

# Print the final value of ans
print(ans)

