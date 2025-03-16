<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Declare variables
	var N int
	var i int
	var sum int64
	var wa int64
	var A [1000000]int
	var sa [1000000]int
	var ans int
	var shou int64

	// Read input
	N, _ = strconv.Atoi(strings.TrimSpace(string(os.Stdin.Read(make([]byte, 1000000000)))))
	// Read N integers into the array A
	for i = 0; i < N; i++ {
		A[i], _ = strconv.Atoi(strings.TrimSpace(string(os.Stdin.Read(make([]byte, 1000000000)))))
		// Add current element to sum
		sum += int64(A[i])
		// Add current index to wa
		wa += int64(i + 1)
	}

	// Check if sum is divisible by wa
	if sum%wa!= 0 {
		ans = 0
	} else {
		// Calculate quotient of sum and wa
		shou = sum / wa
		// Calculate differences between adjacent elements and store in array sa
		for i = 0; i < N; i++ {
			sa[i] = A[(i+1)%N] - A[i] - int(shou)
		}

		// Check if any difference is less than or equal to 0 and divisible by N
		for i = 0; i < N-1; i++ {
			if sa[i] <= 0 && sa[i]%N == 0 {
				ans = 1
			} else {
				ans = 0
				break
			}
		}
	}

	// Print answer
	if ans == 1 {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}

