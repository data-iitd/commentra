

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func solve(N int, M int, Q int, a []int, b []int, c []int, d []int) {
	res := 0 // Initialize the result variable to store the maximum score

	// Define the recursive function to generate sequences
	var rec func(A []int)
	rec = func(A []int) {
		if len(A) == N { // If the sequence length is equal to N
			ans := 0 // Initialize the answer for this sequence
			for i := 0; i < Q; i++ { // Iterate over all constraints
				if A[b[i]-1]-A[a[i]-1] == c[i] { // Check if the constraint is satisfied
					ans += d[i] // Add the value of the constraint to the answer
				}
			}
			if ans > res { // Update the result with the maximum score
				res = ans
			}
			return
		}
		lastMax := 1
		if len(A) > 0 {
			lastMax = A[len(A)-1]
		}
		for i := lastMax; i <= M; i++ { // Generate the next number in the sequence
			rec(append(A, i))
		}
	}

	rec([]int{}) // Start the recursive function with an empty list
	fmt.Println(res) // Print the result
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	const initialBufSize = 4096
	const maxBufSize = 1000000
	scanner.Buffer(make([]byte, initialBufSize), maxBufSize)
	scanner.Split(bufio.ScanWords)
	var N int
	scanner.Scan()
	N, _ = strconv.Atoi(scanner.Text())
	var M int
	scanner.Scan()
	M, _ = strconv.Atoi(scanner.Text())
	var Q int
	scanner.Scan()
	Q, _ = strconv.Atoi(scanner.Text())
	a := make([]int, Q)
	for i := 0; i < Q; i++ {
		scanner.Scan()
		a[i], _ = strconv.Atoi(scanner.Text())
	}
	b := make([]int, Q)
	for i := 0; i < Q; i++ {
		scanner.Scan()
		b[i], _ = strconv.Atoi(scanner.Text())
	}
	c := make([]int, Q)
	for i := 0; i < Q; i++ {
		scanner.Scan()
		c[i], _ = strconv.Atoi(scanner.Text())
	}
	d := make([]int, Q)
	for i := 0; i < Q; i++ {
		scanner.Scan()
		d[i], _ = strconv.Atoi(scanner.Text())
	}
	solve(N, M, Q, a, b, c, d)
}

