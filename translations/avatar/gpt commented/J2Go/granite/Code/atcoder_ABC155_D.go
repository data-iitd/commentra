
package main

import (
	"bufio"
	"bytes"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	var buf bytes.Buffer
	tc := readNum(reader)

	for tc > 0 {
		tc--
		n, k := readTwoNums(reader)
		A := readNNums(reader, n)
		res := solve(n, k, A)
		buf.WriteString(fmt.Sprintf("%d\n", res))
	}

	fmt.Print(buf.String())
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

func solve(n int, k int64, A []int) int64 {
	// Define a large prime number for modulo operations
	const MOD = 100000007

	// Direction vectors for potential grid movements (not used in this code)
	var DX = []int{-1, 0, 1, 0}
	var DY = []int{0, -1, 0, 1}

	// Variables to store the number of elements, a threshold value, and the array of long integers
	var n int
	var k int64
	var a []int

	// Initialize scanner for input
	reader := bufio.NewReader(os.Stdin)

	// Read the number of elements and the threshold value k
	n, k = readTwoNums(reader)

	// Initialize the array to hold the long integers
	a = readNNums(reader, n)

	// Sort the array to facilitate binary search
	sort.Ints(a)

	// Define a large value for infinity
	const INF = 1e18

	// Set the initial bounds for binary search
	l, r := -INF, INF

	// Perform binary search to find the maximum value satisfying the condition
	for l+1 < r {
		c := (l + r) / 2
		if check(n, k, a, c) {
			l = c
		} else {
			r = c
		}
	}

	// Output the result
	return l
}

func check(n int, k int64, A []int, x int64) bool {
	// Total count of valid pairs
	var tot int64

	// Iterate through each element in the array
	for i := 0; i < n; i++ {
		now := int64(A[i])

		// If the current element is non-negative
		if now >= 0 {
			// Perform binary search to count valid pairs
			l, r := 0, n
			for l < r {
				c := (l + r) / 2
				if now*int64(A[c]) < x {
					l = c + 1
				} else {
					r = c
				}
			}
			tot += int64(l)
		} else {
			// If the current element is negative
			l, r := 0, n
			for l < r {
				c := (l + r) / 2
				if now*int64(A[c]) >= x {
					l = c + 1
				} else {
					r = c
				}
			}
			tot += int64(n - l)
		}

		// Adjust total count if the product of the element with itself is less than x
		if int64(A[i])*int64(A[i]) < x {
			tot--
		}
	}

	// Return true if the total count of pairs is less than k
	return tot/2 < k
}

func max(a, b int) int {
	if a >= b {
		return a
	}
	return b
}

func min(a, b int) int {
	if a <= b {
		return a
	}
	return b
}