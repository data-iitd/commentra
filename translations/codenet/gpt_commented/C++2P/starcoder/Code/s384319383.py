
# Python 3 program to find the number of ways to
# partition a string such that every substring
# has an equal number of 'a' and 'b'

# Function to find the number of ways to
# partition a string such that every substring
# has an equal number of 'a' and 'b'
def equalPartition(s):

	# Initialize a vector to count occurrences of each character (a-z)
	cnt = [1] * 26

	# Read characters and count their occurrences
	for i in range(len(s)):
		cnt[ord(s[i]) - ord('a')] += 1

	# Initialize answer with the count of 'a'
	ans = cnt[0]

	# Calculate the product of counts for all characters from 'b' to 'z'
	for i in range(1, 26):
		ans = (ans * cnt[i]) % MOD

	# Output the final result, subtracting 1 to exclude the empty product case
	return ans - 1

# Driver Code
if __name__ == '__main__':

	# Read the input string
	s = input()

	# Find the number of ways to partition a string
	# such that every substring has an equal number
	# of 'a' and 'b'
	ans = equalPartition(s)

	# Print the final result
	print(ans)

