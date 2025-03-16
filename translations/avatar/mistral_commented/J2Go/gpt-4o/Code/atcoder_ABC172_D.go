package main

import (
	"fmt"
)

func main() {
	var n int // We declare an integer variable n to store the number of terms
	var ans int64 = 0 // We initialize an int64 variable ans to 0, which will be used to store the answer

	// We read an integer n from the standard input stream
	fmt.Scan(&n)

	for i := 1; i <= n; i++ { // We start a for loop that iterates from 1 to n
		ans += int64(i) * (int64(n) / int64(i)) * ((int64(n) / int64(i)) + 1) / 2 // In each iteration of the loop, we calculate the contribution of i to the answer using the formula i * (n / i) * ((n / i) + 1) / 2 and add it to the ans variable
	}

	fmt.Println(ans) // After the loop finishes, we print the value of ans to the standard output stream

	// No need to close anything in Go for standard input
}

// <END-OF-CODE>
