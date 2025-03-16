import sys

# Determine the input source based on command-line arguments
fp = sys.stdin
if len(sys.argv) > 1:
	fp = open(sys.argv[1])

# Create a new scanner to read from the determined input source
scanner = fp.readline

# Create a writer to output the result
writer = sys.stdout

# Read the number of elements (n) and the number of restricted positions (m)
n = int(scanner())
m = int(scanner())

# Create a map to store the restricted positions
aa = {}
for i in range(m):
	aa[int(scanner())] = 1

# Initialize the dynamic programming array
dp = [0] * (n+1)
dp[0] = 1

# Fill the dynamic programming array based on restricted positions
for i in range(n):
	for ii in range(1, 3):
		if i+ii > n:
			break
		_, ok = aa[i+ii]
		if ok:
			continue
		dp[i+ii] += dp[i]
		dp[i+ii] %= 1000000007

# Print the result
print(dp[n])

# Flush the writer to ensure all data is written to the output
writer.flush()

