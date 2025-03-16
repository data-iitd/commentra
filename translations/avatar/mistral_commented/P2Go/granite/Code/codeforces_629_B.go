
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Initializing the arrays m and f with zeros for all indices up to N
	const N = 368
	m := make([]int, N)
	f := make([]int, N)

	// Reading the number of operations from the standard input and processing each operation
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		// Reading an operation line and splitting it into components
		fields := scanner.Text()
		x, a, b := fields[:1], fields[2:len(fields)-1], fields[len(fields)-1:]
		// Converting the components a and b to integers
		aInt, _ := strconv.Atoi(a)
		bInt, _ := strconv.Atoi(b)
		// If the operation is 'M', updating the m array accordingly
		if x == "M" {
			m[aInt] += 2
			m[bInt+1] -= 2
		}
		// If the operation is 'F', updating the f array accordingly
		else {
			f[aInt] += 2
			f[bInt+1] -= 2
		}
	}

	// Initializing three variables a, b, and c with zeros
	a, b, c := 0, 0, 0

	// Calculating the prefix sums of m and f arrays
	for i := 0; i < N; i++ {
		// Updating the variables a and b with the sum of m and f arrays respectively
		a += m[i]
		b += f[i]
		// Finding the minimum of a and b and updating the variable c if the minimum is greater than the current value of c
		if a < b && a < c {
			c = a
		} else if b < a && b < c {
			c = b
		}
	}

	// Printing the result, which is the minimum of the prefix sums of m and f arrays
	fmt.Println(c)
}
