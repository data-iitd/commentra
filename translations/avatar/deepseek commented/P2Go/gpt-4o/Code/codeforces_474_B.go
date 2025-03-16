package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	L := []int{}
	var r int = 1

	// Take the first input from the user.
	var input1 string
	fmt.Scanln(&input1)

	// Split the first input into a list of strings and iterate over each string.
	for _, k := range strings.Split(input1, " ") {
		num, _ := strconv.Atoi(k)
		for i := 0; i < num; i++ {
			L = append(L, r)
		}
		r++
	}

	// Take the second input from the user.
	var input2 string
	fmt.Scanln(&input2)

	// Split the second input into a list of strings and iterate over each string.
	for _, j := range strings.Split(input2, " ") {
		index, _ := strconv.Atoi(j)
		fmt.Println(L[index-1])
	}
}

// <END-OF-CODE>
