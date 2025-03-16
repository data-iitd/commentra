package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var L []int
	var r int = 1

	// Read the first input (not used)
	var _ string
	fmt.Scanln(&_)

	// Read the second input
	var input string
	fmt.Scanln(&input)
	for _, k := range strings.Split(input, " ") {
		num, _ := strconv.Atoi(k)
		for i := 0; i < num; i++ {
			L = append(L, r)
		}
		r++
	}

	// Read the third input (not used)
	fmt.Scanln(&_)

	// Read the fourth input and print the results
	fmt.Scanln(&input)
	for _, j := range strings.Split(input, " ") {
		index, _ := strconv.Atoi(j)
		fmt.Println(L[index-1])
	}
}

// <END-OF-CODE>
