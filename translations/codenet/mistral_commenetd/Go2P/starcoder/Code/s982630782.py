
import sys

def main():
	# Initialize an empty map to store the frequency of each number
	m = {}

	# Read the number of test cases N
	N = int(sys.stdin.readline())
	# Read the N integers and store their frequencies in the map
	for i in range(N):
		num = int(sys.stdin.readline())
		if num in m:
			m[num] += 1
		else:
			m[num] = 1

	# Read the number of queries M
	M = int(sys.stdin.readline())
	# For each query, read the number B and the index C, and update the frequency of the number at index C in the map
	for i in range(M):
		B, C = int(sys.stdin.readline()), int(sys.stdin.readline())
		if C in m:
			m[C] += B
		else:
			m[C] = B

	# Create a slice of integers from the map keys
	ints = []
	for k, _ in m.items():
		ints.append(k)

	# Sort the slice in descending order
	ints.sort(reverse=True)

	# Initialize variables for calculating the sum
	rest = N
	sum = 0
	# Iterate through the sorted slice of integers
	for i in ints:
		num = m[i]
		# If the number's frequency is greater than or equal to the remaining number of elements, calculate the sum and break the loop
		if num >= rest:
			sum += rest * i
			break
		# Otherwise, add the product of the number's frequency and its index to the sum, and subtract the number's frequency from the remaining number of elements
		sum += num * i
		rest -= num

	# Print the result
	print(sum)

if __name__ == "__main__":
	main()

