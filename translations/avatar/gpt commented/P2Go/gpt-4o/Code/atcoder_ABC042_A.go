package main

import (
	"fmt"
	"strings"
	"strconv"
)

func main() {
	// Read a line of input
	var input string
	fmt.Scanln(&input)

	// Split the input into components and convert them to integers
	components := strings.Split(input, " ")
	ABC := make([]int, len(components))
	for i, v := range components {
		num, _ := strconv.Atoi(v)
		ABC[i] = num
	}

	// Check if the number 5 appears exactly twice in the slice
	count5 := 0
	sum := 0
	for _, num := range ABC {
		if num == 5 {
			count5++
		}
		sum += num
	}

	// If 5 appears twice, check if the sum of the numbers in the slice equals 17
	if count5 == 2 {
		if sum == 17 {
			fmt.Println("YES")
		} else {
			fmt.Println("NO")
		}
	} else {
		// If 5 does not appear exactly twice, print 'NO'
		fmt.Println("NO")
	}
}

// <END-OF-CODE>
