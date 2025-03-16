package main

import (
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	// Read input from standard input
	input, _ := os.ReadFile("/dev/stdin")
	lines := strings.Split(string(input), "\n")

	// Parse the second line of input
	arrStr := strings.Fields(lines[1])
	arr := make([]int, len(arrStr))
	for i, s := range arrStr {
		arr[i], _ = strconv.Atoi(s)
	}

	// Sort the array
	sort.Ints(arr)

	// Check if any element is not divisible by the first element
	first := arr[0]
	anyNotDivisible := false
	for _, x := range arr {
		if x%first != 0 {
			anyNotDivisible = true
			break
		}
	}

	// Print the result
	if anyNotDivisible {
		fmt.Println(first)
	} else {
		fmt.Println(-1)
	}
}

// <END-OF-CODE>
