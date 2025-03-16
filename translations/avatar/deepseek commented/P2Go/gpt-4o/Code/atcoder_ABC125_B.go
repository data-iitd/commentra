package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var N int
	fmt.Scan(&N) // Taking an integer input N

	var V []int
	var C []int

	// Taking the first line of space-separated integers and storing them in slice V
	var inputV string
	fmt.Scan(&inputV)
	for _, s := range strings.Split(inputV, " ") {
		num, _ := strconv.Atoi(s)
		V = append(V, num) // Converting each element in V to an integer
	}

	// Taking the second line of space-separated integers and storing them in slice C
	var inputC string
	fmt.Scan(&inputC)
	for _, s := range strings.Split(inputC, " ") {
		num, _ := strconv.Atoi(s)
		C = append(C, num) // Converting each element in C to an integer
	}

	// Initializing a slice named list with a single element 0 and an integer ans set to 0
	list := []int{0}
	ans := 0

	// Entering a for loop that iterates N times
	for i := 0; i < N; i++ {
		// Checking if the difference between the i-th element of V and the i-th element of C is greater than 0
		if V[i]-C[i] > 0 {
			X := V[i] // Assigning the i-th element of V to X
			Y := C[i] // Assigning the i-th element of C to Y
			list = append(list, X-Y) // Appending the difference X - Y to the list
		}
	}

	// Printing the sum of the list
	sum := 0
	for _, value := range list {
		sum += value
	}
	fmt.Println(sum)
}

// <END-OF-CODE>
