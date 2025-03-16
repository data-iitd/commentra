package main

import (
	"fmt"
	"strings"
)

func main() {
	var input string
	fmt.Scanln(&input)

	// Split the input string and convert to integers
	parts := strings.Split(input, " ")
	ABC := make([]int, len(parts))
	for i, part := range parts {
		fmt.Sscanf(part, "%d", &ABC[i])
	}

	// Count occurrences of 5
	count5 := 0
	for _, num := range ABC {
		if num == 5 {
			count5++
		}
	}

	// Check conditions and print result
	if count5 == 2 {
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
		fmt.Println("NO")
	}
}

// <END-OF-CODE>
