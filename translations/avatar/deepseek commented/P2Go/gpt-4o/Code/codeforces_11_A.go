package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var n, d int
	fmt.Scan(&n, &d)
	// Taking input for two variables `n` and `d`

	x := make([]int, n)
	m := 0
	q := 0
	// Initializing a slice `x` and two integer variables `m` and `q` to 0

	var input string
	fmt.Scan(&input)
	// Taking input for the list `x` as a string

	// Splitting the input string and converting to integers
	for i, s := range strings.Split(input, " ") {
		x[i], _ = strconv.Atoi(s)
	}

	for a := 0; a < len(x)-1; a++ {
		if x[a] >= x[a+1] {
			q = (x[a] - x[a+1]) / d + 1
			m += q
			x[a+1] += q * d
		}
	}
	// Checking if the current element is greater than or equal to the next element
	// Calculating the number of steps `q` needed to make the current element less than the next element by at least `d`
	// Updating the value of `m` by adding `q` to it
	// Updating the next element in the slice `x` by adding `q * d` to it

	fmt.Println(m)
	// Printing the value of `m`
}

// <END-OF-CODE>
