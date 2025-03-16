package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	// Read user input
	var input string
	fmt.Scanln(&input)

	// Split the input by space and convert each element to an integer
	parts := strings.Split(input, " ")
	var ABC []int
	for _, part := range parts {
		num, _ := strconv.Atoi(part)
		ABC = append(ABC, num)
	}

	// Check if the slice ABC contains exactly 2 occurrences of the integer 5
	count := 0
	for _, num := range ABC {
		if num == 5 {
			count++
		}
	}

	if count == 2 {
		// If the condition is met, print 'YES' if the sum of all elements in the slice ABC equals 17
		sum := 0
		for _, num := range ABC {
			sum += num
		}
		if sum == 17 {
			fmt.Println("YES")
		} else {
			fmt.Println("NO")
		}
	} else {
		// If the condition is not met, print 'NO'
		fmt.Println("NO")
	}
}
