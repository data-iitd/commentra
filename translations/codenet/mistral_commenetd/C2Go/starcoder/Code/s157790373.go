
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

// Global variables
var n int
var A []int
var q int
var M int
<<<<<<< HEAD
var flag int

// Function to check if there is a subsequence of given length'm' in the array 'A' starting from index 'i'
func solve(i int, m int) int {
	// Base case: If index 'i' goes beyond the size of the array 'A', return false as no subsequence can start from this index
	if i > n {
		return 0
=======
var flag bool

// Function to check if there is a subsequence of given length'm' in the array 'A' starting from index 'i'
func solve(i int, m int) bool {
	// Base case: If index 'i' goes beyond the size of the array 'A', return false as no subsequence can start from this index
	if i > n {
		return false
>>>>>>> 98c87cb78a (data updated)
	}

	// Base case: If length'm' is zero, any empty subsequence of length zero can be formed from any index in the array 'A'
	if m < 0 {
<<<<<<< HEAD
		return 0
=======
		return false
>>>>>>> 98c87cb78a (data updated)
	}

	// Base case: If length'm' is equal to zero or the difference between the elements at index 'i+1' and 'i' is equal to'm', a subsequence of length'm' can be formed starting from index 'i'
	if m == 0 || m-A[i+1] == 0 {
<<<<<<< HEAD
		flag = 1
		return 1
=======
		flag = true
		return true
>>>>>>> 98c87cb78a (data updated)
	}

	// Recursive case: If length'm' cannot be formed from the element at index 'i', check if it can be formed from the elements starting from index 'i+1'
	// Not using the element at index 'i' to form the subsequence of length'm'
	solve(i+1, m)

	// Using the element at index 'i' to form the subsequence of length'm'
	solve(i+1, m-A[i])
<<<<<<< HEAD

	return 0
=======
>>>>>>> 98c87cb78a (data updated)
}

func main() {
	// Reading the size of the array 'A'
<<<<<<< HEAD
	n, _ = strconv.Atoi(strings.TrimSpace(string(os.Stdin.Read(make([]byte, 1000000)))))
=======
	n, _ = strconv.Atoi(strings.TrimSpace(string(os.Stdin.Read(make([]byte, 1024)))))
>>>>>>> 98c87cb78a (data updated)

	// Reading the elements of the array 'A'
	A = make([]int, n)
	for i := 0; i < n; i++ {
<<<<<<< HEAD
		A[i], _ = strconv.Atoi(strings.TrimSpace(string(os.Stdin.Read(make([]byte, 1000000)))))
	}

	// Reading the number of queries
	q, _ = strconv.Atoi(strings.TrimSpace(string(os.Stdin.Read(make([]byte, 1000000)))))
=======
		A[i], _ = strconv.Atoi(strings.TrimSpace(string(os.Stdin.Read(make([]byte, 1024)))))
	}

	// Reading the number of queries
	q, _ = strconv.Atoi(strings.TrimSpace(string(os.Stdin.Read(make([]byte, 1024)))))
>>>>>>> 98c87cb78a (data updated)

	// Loop through all the queries
	for i := 0; i < q; i++ {
		// Reading the length of subsequence to be checked in the current query
<<<<<<< HEAD
		M, _ = strconv.Atoi(strings.TrimSpace(string(os.Stdin.Read(make([]byte, 1000000)))))

		// Initializing the flag to false
		flag = 0
=======
		M, _ = strconv.Atoi(strings.TrimSpace(string(os.Stdin.Read(make([]byte, 1024)))))

		// Initializing the flag to false
		flag = false
>>>>>>> 98c87cb78a (data updated)

		// Calling the function'solve' to check if there is a subsequence of given length 'M' in the array 'A'
		solve(0, M)

		// If a subsequence of given length 'M' is found, print 'yes'
<<<<<<< HEAD
		if flag == 1 {
=======
		if flag == true {
>>>>>>> 98c87cb78a (data updated)
			fmt.Println("yes")
		} else {
			// If no subsequence of given length 'M' is found, print 'no'
			fmt.Println("no")
		}
	}
}

