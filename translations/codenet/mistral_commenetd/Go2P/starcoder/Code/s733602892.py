
import sys

def main():
	# Read input: N and K
	N, K = map(int, input().split())

	# Read input: N integers As
	As = list(map(int, input().split()))

	# Read input: N integers Fs
	Fs = list(map(int, input().split()))

	# Sort As and Fs in ascending and descending order respectively
	As.sort()
	Fs.sort(reverse=True)

	# Calculate the score for each element in As
	scores = [As[i] * Fs[i] for i in range(N)]

	# Sort scores in descending order
	scores.sort(reverse=True)

	# Binary search to find the answer
	ok = scores[0]
	ng = -1
	while ok-ng > 1:
		mid = (ok + ng) // 2

		# Check if it's possible to distribute the flowers to K students with the given mid score
		isOK = True
		k = K
		for i in range(N):
			if As[i]*Fs[i] > mid:
				# Subtract the difference between mid and the product of the current element from the remaining flowers
				k -= As[i] - mid//Fs[i]
			if k < 0:
				# If the remaining flowers are not enough to distribute to all students, it's not possible to distribute the flowers with the given mid score
				isOK = False
				break
		if isOK:
			# If it's possible to distribute the flowers with the given mid score, update ok with mid
			ok = mid
		else:
			# If it's not possible to distribute the flowers with the given mid score, update ng with mid
			ng = mid

	# Print the answer
	print(ok)

if __name__ == '__main__':
	main()

