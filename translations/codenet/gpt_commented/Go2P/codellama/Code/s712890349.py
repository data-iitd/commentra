
# Go:
package main

import (
	"bufio"
	"fmt"
	"os"
)

// Block represents a contiguous segment of characters with a specific value and length.
type Block struct {
	Value string // The character value of the block
	Len   int    // The length of the block
}

func main() {
	# Read input values for N (length of the string) and K (maximum number of '0's allowed)
	N, K, ans = map(int, input().split())

	# Read the input string S
	S = input()

	# Generate run-length encoded blocks from the input string S
	blocks = RunLength(S)

	# Initialize variables for the sliding window approach
	sum, zero, l = 0, 0, 0

	# Iterate through the blocks to find the maximum length of segments with at most K '0's
	for r in range(len(blocks)):
		sum += blocks[r].Len # Add the length of the current block to the sum

		# Count the number of '0' blocks encountered
		if blocks[r].Value == "0":
			zero += 1

		# If the count of '0' blocks exceeds K, shrink the window from the left
		while K < zero:
			sum -= blocks[l].Len # Subtract the length of the leftmost block from the sum
			if blocks[l].Value == "0":
				zero -= 1 # Decrease the count of '0' blocks
			l += 1 # Move the left pointer to the right

		# Update the answer with the maximum sum found so far
		ans = max(ans, sum)

	# Print the maximum length of segments with at most K '0's
	print(ans)

# Go:
func RunLength(s string) []Block {
	var r []Block // Slice to hold the resulting blocks
	if len(s) == 0 {
		return r // Return empty slice if input string is empty
	}

	# Initialize the first block with the first character of the string
	t := Block{Value: string(s[0]), Len: 1}
	for _, v := range s[1:] {
		# If the current character matches the block's value, increase the length
		if t.Value == string(v) {
			t.Len++
		} else {
			# Otherwise, append the current block to the result and start a new block
			r = append(r, t)
			t = Block{Value: string(v), Len: 1}
		}
	}
	# Append the last block to the result
	r = append(r, t)
	return r // Return the slice of blocks
}

# Go:
func Max(a, b int) int {
	if b > a {
		return b // Return b if it is greater than a
	}
	return a // Otherwise, return a
}

