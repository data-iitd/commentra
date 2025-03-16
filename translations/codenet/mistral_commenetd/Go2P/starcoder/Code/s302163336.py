
# Initialize scanner
import sys

sc = sys.stdin

# Read the number of elements n and m from the standard input
n = int(sc.readline())
m = int(sc.readline())

# Initialize h array with n elements and good array with n boolean values
h = [0] * n
good = [True] * n

# Read n integers from the standard input and initialize h and good arrays
for i in range(n):
	h[i] = int(sc.readline())

# Process m queries
for i in range(m):
	# Read two integers ai and bi from the standard input
	ai = int(sc.readline()) - 1
	bi = int(sc.readline()) - 1

	# Compare the heights of h[ai] and h[bi]
	if h[ai] > h[bi]:
		# If h[ai] is greater than h[bi], mark good[bi] as false
		good[bi] = False
	elif h[ai] < h[bi]:
		# If h[ai] is less than h[bi], mark good[ai] as false
		good[ai] = False
	else:
		# If heights are equal, mark both good[ai] and good[bi] as false
		good[ai] = False
		good[bi] = False

# Initialize answer variable ans to 0
ans = 0

# Count the number of good elements in the h array
for i in range(n):
	if good[i]:
		# Increment ans if good[i] is true
		ans += 1

# Print the answer
print(ans)

