
###
# Code
###

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

var (
	N, K int
	A     []int
)

func main() {
	// Initialize input variables
	N, K = readTwoNums()

	// Initialize list 'A' with input values
	A = readNNums(N)

	// Sort list 'A' in ascending order
	sort.Ints(A)

	// Initialize variables for binary search
	ll := -1e18 - 1
	rr := 1e18 + 1

	// Perform binary search until 'll + 1' is less than 'rr'
	for ll+1 < rr {
		// Calculate mid value for binary search
		x := (ll + rr) / 2

		// Initialize variable 'tot' to store total count of elements
		tot := 0

		// Iterate through list 'A' and calculate total count of elements that satisfy the condition
		for i := 0; i < N; i++ {
			// Check if current element 'A[i]' is negative
			if A[i] < 0 {
				// Initialize variables 'l' and 'r' for binary search in the range of indices
				l, r := 0, N

				// Perform binary search to find the index 'c' such that A[i] * A[c] >= x
				for l+1 < r {
					c := (l + r) / 2
					if A[i]*A[c] < x {
						l = c
					} else {
						r = c
					}
				}

				// Update 'tot' with the number of elements greater than 'c'
				tot += N - r
			} else {
				l, r := 0, N
				for l+1 < r {
					c := (l + r) / 2
					if A[i]*A[c] < x {
						l = c
					} else {
						r = c
					}
				}
				tot += r
			}

			// Update 'tot' with the contribution of current element 'A[i]'
			if A[i]*A[i] < x {
				tot--
			}
		}

		// Check if total count of elements is greater than or equal to 'K'
		if tot >= K {
			// Update 'll' if condition is satisfied
			ll = x
		} else {
			// Update 'rr' if condition is not satisfied
			rr = x
		}
	}

	// Print the final answer
	fmt.Println(ll)
}

func readInt() int {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	var n int
	sc.Scan()
	fmt.Sscanf(sc.Text(), "%d", &n)
	return n
}

func readTwoNums() (int, int) {
	res := make([]int, 2)
	p := 0
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	for sc.Scan() {
		fmt.Sscanf(sc.Text(), "%d", &res[p])
		p++
	}
	return res[0], res[1]
}

func readNNums(n int) []int {
	res := make([]int, n)
	x := 0
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	for sc.Scan() {
		fmt.Sscanf(sc.Text(), "%d", &res[x])
		x++
	}
	return res
}

func readUint64() uint64 {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	var n uint64
	sc.Scan()
	fmt.Sscanf(sc.Text(), "%d", &n)
	return n
}

func readInt64() int64 {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	var n int64
	sc.Scan()
	fmt.Sscanf(sc.Text(), "%d", &n)
	return n
}

func min(a, b int) int {
	if a <= b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a >= b {
		return a
	}
	return b
}

func minUint64(a, b uint64) uint64 {
	if a <= b {
		return a
	}
	return b
}

func maxUint64(a, b uint64) uint64 {
	if a >= b {
		return a
	}
	return b
}

func minInt64(a, b int64) int64 {
	if a <= b {
		return a
	}
	return b
}

func maxInt64(a, b int64) int64 {
	if a >= b {
		return a
	}
	return b
}

