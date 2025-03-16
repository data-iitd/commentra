
# Read two integers n and k from the standard input using input()
n, k = map(int, input().split())
# Initialize variable cnt to zero
cnt = 0
# Loop through n times using a for loop
for _ in range(n):
	# Read an integer h from the standard input using input()
	h = int(input())
	# If h is greater than or equal to k, increment cnt by 1
	if h >= k:
		cnt += 1
# Print the value of cnt to the standard output using print()
print(cnt)
# End of code
