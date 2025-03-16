# Read the total number of characters (N) from input
N = int(input())

# Read the string of characters (c) from input
c = input()

# Count the number of 'W' characters in the input string
num_w = c.count("W")

# Calculate the number of 'R' characters by subtracting the count of 'W' from N
num_r = N - num_w

# Create a target string (comp) consisting of 'R' followed by 'W' based on their counts
comp = "R" * num_r + "W" * num_w

# Initialize a variable to count the number of mismatches
ans = 0

# Loop through the first num_r characters of the input string
for i in range(num_r):
    # Check if the character in the input string does not match the corresponding character in the target string
    if c[i] != comp[i]:
        # Increment the mismatch count
        ans += 1

# Determine the minimum value among the counts of 'W', 'R', and the mismatch count
ans = min(num_w, num_r, ans)

# Print the result which is the minimum number of changes needed
print(ans)
