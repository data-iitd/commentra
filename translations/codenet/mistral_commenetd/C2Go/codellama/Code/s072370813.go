package main

import "fmt"

func main() {
	// Declare variables
	var N int // Number of elements in the array
	var i int // Loop counter
	var sum int64 = 0 // Sum of all elements in the array
	var wa int64 = 0 // Sum of all indices from 1 to N
	var A [N]int // Array to store input elements
	var sa [N]int // Array to store differences between adjacent elements
	var ans int = 0 // Answer flag
	var shou int64 = 0 // Quotient of sum and wa

	// Read input
	fmt.Scan(&N)
	// Read N integers into the array A
	for i = 0; i < N; i++ {
		fmt.Scan(&A[i])
		// Add current element to sum
		sum += int64(A[i])
		// Add current index to wa
		wa += int64(i + 1)
	}

	// Check if sum is divisible by wa
	if sum%wa != 0 {
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
			if sa[i] <= 0 && !(sa[i] % N) {
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

