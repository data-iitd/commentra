
# Define constants
N_MAX = 100
P_MAX = 100
DP_ARRAY_SIZE = (N_MAX * P_MAX / 32 + 1)

# Define helper functions
def MIN(a, b):
	return a if a < b else b

def MAX(a, b):
	return a if a > b else b

def ABS(a):
	return a if a >= 0 else -a

def ABSS(a, b):
	return a if a > b else b - a

# Function to find the last occurrence of a substring in a string
def strrstr(string, pattern):
	offset = 0
	lastP = None

	searchResult = None
	while (searchResult = strstr(string[offset:], pattern))!= None and string[offset]!= '\0':
		lastP = searchResult
		offset += 1

	return lastP

# Function to compare two pointers for qsort
def compare_f(a, b):
	return a < b

# Function to calculate the number of combinations of n items taken r at a time
def comb(n, r):
	result = 1

	for i in range(0, r):
		result *= n - i
		result /= i + 1

	return result

# Function to find the greatest common divisor of two numbers
def gcd(m, n):
	temp = 0

	while m%n!= 0:
		temp = n
		n = m % n
		m = temp

	return n

# Read input string from standard input
S = raw_input()

# Calculate length of input string
len = len(S)
found = False

# Loop through each character in pattern base string
for offset in range(0, len(patternBase)):
	# Copy substring up to current character to top variable
	top = patternBase[0:offset]

	# Copy substring from current character to end of pattern base string to bottom variable
	bottom = patternBase[offset:len(patternBase)]

	# Search for top substring in input string
	topSearch = strstr(S, top)

	# If top substring is found
	if topSearch!= None:
		# Search for bottom substring after top substring in input string
		bottomSearch = strrstr(topSearch[offset:], bottom)

		# If bottom substring is found
		if bottomSearch!= None:
			# Calculate number of separators between top and bottom substrings
			sepCount = 0

			# If topSearch is not the first occurrence of top substring in input string
			if topSearch!= S:
				sepCount += 1

			# If topSearch is not the same as bottomSearch
			if topSearch[offset:]!= bottomSearch:
				sepCount += 1

			# If bottomSearch is not the last character in input string
			if bottomSearch[len(bottom)]!= '\0':
				sepCount += 1

			# If number of separators is less than or equal to 1
			if sepCount <= 1:
				found = True
				break

# Print output based on whether pattern is found or not
print "YES" if found else "NO"

