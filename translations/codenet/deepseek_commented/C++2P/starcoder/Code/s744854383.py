
# Read the number of elements N
N = int(input())

# Read N integers into a vector `a`
a = [int(input()) for i in range(N)]

# Initialize idx to 1 and ans to 0
idx = 1
ans = 0

# Iterate through the vector `a`
for i in range(N):
	# If the current element is equal to `idx`, increment `idx`
	if a[i] == idx:
		idx += 1
	else:
		# If not, increment `ans`
		ans += 1

# If `idx` is still 1, it means no elements matched, so print `-1`
if idx == 1:
	print(-1)
else:
	# Otherwise, print `ans`
	print(ans)

# 