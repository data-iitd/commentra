import sys

def main():
	# Read the number of elements N and the threshold K
	N, K = map(int, input().split())

	# Read the two slices of integers As and Fs
	As = list(map(int, input().split()))
	Fs = list(map(int, input().split()))

	# Sort the As slice in ascending order
	As.sort()
	# Sort the Fs slice in descending order
	Fs.sort(reverse=True)

	# Create a slice to hold the scores calculated from As and Fs
	scores = [As[i] * Fs[i] for i in range(N)]

	# Sort the scores in descending order
	scores.sort(reverse=True)

	# Initialize binary search boundaries
	ok = scores[0] # The maximum possible score
	ng = -1        # The minimum possible score

	# Perform binary search to find the maximum score that can be achieved
	while ok-ng > 1:
		mid = (ok + ng) // 2 # Calculate the midpoint of the current range

		isOK = True # Flag to check if the current mid is achievable
		k = K       # Remaining threshold to adjust scores
		for i in range(N):
			# If the current score exceeds mid, calculate how much we need to reduce
			if As[i]*Fs[i] > mid:
				k -= As[i] - mid//Fs[i]
			# If we exceed the allowed threshold, mark isOK as false
			if k < 0:
				isOK = False
		# Adjust binary search boundaries based on whether mid is achievable
		if isOK:
			ok = mid # If achievable, move the upper boundary
		else:
			ng = mid # If not achievable, move the lower boundary
	# Print the maximum achievable score
	print(ok)

# Initialize a scanner for reading input
sc = sys.stdin

# Read reads the next token from input as a string
def Read():
	return sc.readline().strip()

# ReadInt reads the next integer from input and returns it
def ReadInt():
	return int(Read())

# Main function
if __name__ == "__main__":
	main()

