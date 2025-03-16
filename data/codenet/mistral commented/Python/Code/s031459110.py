# Take an integer input N from the user
N = int(input())

# Take a string input c from the user
c = input()

# Calculate the number of 'W' characters in the string c
num_w = c.count("W")

# Calculate the number of 'R' characters in the string N
num_r = N - num_w

# Create a new string comp by concatenating num_r number of 'R' characters and num_w number of 'W' characters
comp = "R" * num_r + "W" * num_w

# Initialize a variable ans to 0
ans = 0

# Iterate through the first num_r indices of the string c and compare each character with the corresponding character in the string comp
for i in range(num_r):
    # If the characters do not match, increment the value of ans by 1
    if c[i] != comp[i]:
        ans += 1

# Find the minimum value among num_w, num_r, and ans
ans = min(num_w, num_r, ans)

# Print the minimum value
print(ans)
