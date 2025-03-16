
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	// Read input values for N (number of elements) and K (threshold count)
	N, K := readTwoNums()

	// Read the list of integers and sort it
	A := readNNums(N)
	sort.Ints(A)

	// Initialize the lower and upper bounds for binary search
	ll, rr := -1e18-1, 1e18+1

	// Perform binary search to find the maximum value x such that the count of pairs (i, j) with A[i] * A[j] < x is at least K
	for ll+1 < rr {
		// Calculate the mid-point of the current bounds
		x := (ll + rr) / 2
		tot := 0 // Initialize the total count of valid pairs

		// Iterate through each element in the sorted list A
		for i := 0; i < N; i++ {
			if A[i] < 0 { // If the current element is negative
				l, r := -1, N
				// Perform binary search to find the count of elements that can form a valid pair with A[i]
				for l+1 < r {
					c := (l + r) / 2
					if A[i]*A[c] < x { // Check if the product is less than x
						r = c // Move the right bound down
					} else {
						l = c // Move the left bound up
					}
				}
				// Count how many elements can form a valid pair with A[i]
				tot += N - r
			} else { // If the current element is non-negative
				l, r := -1, N
				// Perform binary search to find the count of elements that can form a valid pair with A[i]
				for l+1 < r {
					c := (l + r) / 2
					if A[i]*A[c] < x { // Check if the product is less than x
						l = c // Move the left bound up
					} else {
						r = c // Move the right bound down
					}
				}
				// Count how many elements can form a valid pair with A[i]
				tot += r
			}

			// Adjust the total count if A[i] forms a pair with itself
			if A[i]*A[i] < x {
				tot--
			}
		}

		// Since each pair (i, j) is counted twice, divide the total count by 2
		tot /= 2

		// Adjust the binary search bounds based on the total count of pairs
		if tot < K {
			ll = x // If the count is less than K, move the lower bound up
		} else {
			rr = x // If the count is at least K, move the upper bound down
		}
	}

	// Print the final result, which is the largest x found
	fmt.Println(ll)
}

func readInt(bytes []byte, from int, val *int) int {
	i := from
	sign := 1
	if bytes[i] == '-' {
		sign = -1
		i++
	}
	tmp := 0
	for i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' {
		tmp = tmp*10 + int(bytes[i]-'0')
		i++
	}
	*val = tmp * sign
	return i
}

func readNum(reader *bufio.Reader) (a int) {
	bs, _ := reader.ReadBytes('\n')
	readInt(bs, 0, &a)
	return
}

func readTwoNums(reader *bufio.Reader) (a int, b int) {
	res := readNNums(reader, 2)
	a, b = res[0], res[1]
	return
}

func readThreeNums(reader *bufio.Reader) (a int, b int, c int) {
	res := readNNums(reader, 3)
	a, b, c = res[0], res[1], res[2]
	return
}

func readNNums(reader *bufio.Reader, n int) []int {
	res := make([]int, n)
	x := 0
	bs, _ := reader.ReadBytes('\n')
	for i := 0; i < n; i++ {
		for x < len(bs) && (bs[x] < '0' || bs[x] > '9') && bs[x]!= '-' {
			x++
		}
		x = readInt(bs, x, &res[i])
	}
	return res
}

func readUint64(bytes []byte, from int, val *uint64) int {
	i := from

	var tmp uint64
	for i < len(bytes) && bytes[i] >= '0' && bytes[i] <= '9' {
		tmp = tmp*10 + uint64(bytes[i]-'0')
		i++
	}
	*val = tmp

	return i
}

func main() {
	reader := bufio.NewReader(os.Stdin)

	tc := readNum(reader)

	for tc > 0 {
		tc--
		n, k := readTwoNums(reader)
		A := readNNums(reader, n)
		sort.Ints(A)

		var left, right int = -1e18, 1e18

		for left+1 < right {
			mid := (left + right) / 2
			cnt := 0

			for i := 0; i < n; i++ {
				if A[i] < 0 {
					j := search(A, -mid/A[i])
					cnt += n - j
				} else {
					j := search(A, mid/A[i]+1)
					cnt += j
				}
				if A[i]*A[i] < mid {
					cnt--
				}
			}

			cnt /= 2

			if cnt < k {
				left = mid
			} else {
				right = mid
			}
		}

		fmt.Println(left)
	}
}

func search(nums []int, target int) int {
	left, right := 0, len(nums)

	for left < right {
		mid := (left + right) / 2
		if nums[mid] >= target {
			right = mid
		} else {
			left = mid + 1
		}
	}

	return left
}

func max(a, b int) int {
	if a >= b {
		return a
	}
	return b
}