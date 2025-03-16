package main

import (
	"fmt"
	"strings"
)

func main() {
	var input string
	fmt.Scanln(&input) // Take input from user

	// Split the input string into a slice of strings
	strs := strings.Split(input, " ")
	ABC := make([]int, len(strs))

	// Convert the slice of strings to a slice of integers
	for i, str := range strs {
		fmt.Sscanf(str, "%d", &ABC[i])
	}

	// Check if the slice contains exactly two 5s
	count5 := 0
	for _, num := range ABC {
		if num == 5 {
			count5++
		}
	}

	// Check if the sum of the elements in ABC is 17
	sum := 0
	for _, num := range ABC {
		sum += num
	}

	if count5 == 2 {
		if sum == 17 {
			fmt.Println("YES")
		} else {
			fmt.Println("NO")
		}
	} else {
		fmt.Println("NO")
	}
}

// <END-OF-CODE>
