#include <stdbool.h>
#include <stdio.h>

int main() {
	# Declare variables
	n = 0                      # Number of elements in the array
	a = []                     # Array to store the elements
	cnt = 1                    # Counter to store the number of increasing subsequences
	isup = False               # Flag to check if the subsequence is increasing or not
	issame = False             # Flag to check if all elements in a subsequence are the same

	# Read the number of elements from the user
	n = int(input())

	# Read the elements of the array from the user
	for i in range(n):
		a.append(int(input()))

	# Determine if the first two elements form an increasing subsequence
	if a[0] < a[1]:
		isup = True
	elif a[0] > a[1]:
		isup = False
	else:
		issame = True

	# Check for increasing subsequences in the array
	for i in range(1, n - 1):
		# If the previous subsequence is made of same elements
		if issame:
			# If the current element is not the same as the next one
			if a[i] != a[i + 1]:
				# Reset the flags and determine if the new subsequence is increasing or not
				issame = False
				if a[i] < a[i + 1]:
					isup = True
				else:
					isup = False
				cnt += 1
		else:
			# If the subsequence is increasing
			if isup and a[i] <= a[i + 1]:
				# Continue the loop
				pass
			elif not isup and a[i] >= a[i + 1]:
				# The subsequence is decreasing, reset the flags and continue the loop
				isup = False
				issame = False
				cnt += 1
			else:
				# Check for the next element to determine if it starts a new increasing subsequence
				if i + 2 < n:
					if a[i + 1] < a[i + 2]:
						isup = True
					elif a[i + 1] > a[i + 2]:
						isup = False
					else:
						issame = True
					cnt += 1
				else:
					# Reach the end of the array, increment the counter and break the loop
					cnt += 1
					break

	# Print the number of increasing subsequences
	print(cnt)

	# Return 0 to indicate successful execution
	return 0
}

