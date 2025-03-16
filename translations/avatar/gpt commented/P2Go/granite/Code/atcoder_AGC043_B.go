
```go
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func twosInFactorial(n int) int {
	// Calculate the number of factors of 2 in n! by subtracting the count of 1s in the binary representation of n from n
	return n - len(strconv.FormatInt(int64(n), 2))
}

func parityOfNCR(n, i int) bool {
	// Determine the parity (even or odd) of the binomial coefficient C(n, i)
	f := twosInFactorial  // Reference to the function that calculates the number of factors of 2
	// The binomial coefficient C(n, i) is odd if the number of factors of 2 in n! is greater than the sum of factors of 2 in (n-i)! and i!
	return f(n)-f(n-i)-f(i) > 0
}

func main() {
	// Read an integer n from input
	n, _ := strconv.Atoi(bufio.NewReader(os.Stdin).ReadLine()[2:])
	// Read a list of integers, subtracting 1 from each input value
	nums := make([]int, n)
	for i := 0; i < n; i++ {
		num, _ := strconv.Atoi(bufio.NewReader(os.Stdin).ReadLine()[2:])
		nums[i] = num - 1
	}

	noOne := false  // Flag to check if there are no '1's in the input list
	if!contains(nums, 1) {
		// If there are no '1's, divide each number in nums by 2
		for i := 0; i < n; i++ {
			nums[i] /= 2
		}
		noOne = true  // Set the flag to True since there were no '1's
	}

	isOdd := false  // Flag to track if the overall parity is odd
	for i, num := range nums {
		// Check the parity of C(n-1, i) and if num is odd
		if!parityOfNCR(n-1, i) && num%2 == 1 {
			isOdd =!isOdd  // Toggle the isOdd flag if the conditions are met
		}
	}

	// Print the result based on the parity
	if!isOdd {
		fmt.Println(0)  // If the overall parity is even, print 0
	} else {
		fmt.Println(1 << noOne)  // If odd, print 1 or 2 based on the noOne flag
	}
}

func contains(nums []int, target int) bool {
	for _, num := range nums {
		if num == target {
			return true
		}
	}
	return false
}

