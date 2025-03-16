package main

import (
	"fmt"
)

func main() {
	var N int
	fmt.Scan(&N) // Read the number of elements N from the user
	A := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i]) // Read N integers from the user and store them in the array A
	}
	if possible(N, A) { // Call the possible method to check if the array A can be rearranged to satisfy a certain condition
		fmt.Println("YES") // Print "YES" if the condition is satisfied
	} else {
		fmt.Println("NO") // Print "NO" if the condition is not satisfied
	}
}

func possible(N int, A []int) bool {
	var sum int64 = 0
	for i := 0; i < N; i++ {
		sum += int64(A[i]) // Calculate the sum of the elements in the array A
	}
	var NS int64 = int64(N) * int64(N+1) / 2 // Calculate the sum of the first N natural numbers (NS)
	if sum%NS != 0 {
		return false // Check if the sum of the array A is divisible by NS. If not, return false
	}
	var K int64 = sum / NS // Calculate the value of K, which is the average of the differences between consecutive elements in the array A
	for i := 0; i < N; i++ {
		var j int = i
		if i > 0 {
			j = i - 1
		}
		var d int64 = K - int64(A[i]-A[j]) // Calculate the difference between the current element and the previous element
		if d < 0 || d%int64(N) != 0 {
			return false // Check if the difference is negative or not divisible by N. If so, return false
		}
	}
	return true // If all elements satisfy the condition, return true
}

