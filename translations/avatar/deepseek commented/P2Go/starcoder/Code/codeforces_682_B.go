package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// I is a helper function that returns a slice of integers from a string
func I(s string) []int {
	a := strings.Split(s, " ")
	res := make([]int, len(a))
	for i, v := range a {
		res[i], _ = strconv.Atoi(v)
	}
	return res
}

func main() {
	// Read the number of elements
	n := 0
	fmt.Scanf("%d", &n)

	// Read the list of elements
	l := I(bufio.NewReader(os.Stdin).ReadString('\n'))

	// Initialize variables
	f := 1
	l = append(l, 0)
	l.sort()
	c := 0

	// Iterate through the list to find the maximum number of unique elements
	for i := 0; i < len(l); i++ {
		if l[i] > c {
			c++
		}
	}

	// Print the result
	fmt.Println(c + 1)
}

