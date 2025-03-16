
package main

import (
	"fmt"
	"math"
	"os"
	"strconv"
)

func main() {
	var n int
	var div int64 = 1000000007
	var ans int64
	var a int64
	var count1 int64
	var i int
	var j int
	var A []int64

	// Read the number of elements
	n, _ = strconv.Atoi(os.Args[1])

	// Initialize array A to store n long integers
	A = make([]int64, n)

	// Read n long integers from the user and store them in array A
	for i = 0; i < n; i++ {
		A[i], _ = strconv.ParseInt(os.Args[i+2], 10, 64)
	}

	// Iterate over each bit position from 0 to 59
	for i = 0; i < 60; i++ {
		a = 0
		count1 = 0

		// Count the number of elements with the current bit set to 1
		for j = 0; j < n; j++ {
			if (A[j]>>i)&1 == 1 {
				count1++
			}
		}

		// Calculate the contribution of the current bit position
		a = a + count1*(n-count1)

		// Shift the contribution left by 1 bit for each lower bit position and take modulo
		for j = 0; j < i; j++ {
			a = (a << 1) % div
		}

		// Add the contribution to the answer and take modulo
		ans += a
		ans %= div
	}

	// Print the result
	fmt.Println(ans)
}

