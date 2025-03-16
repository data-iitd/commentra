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

	// Split the input by space and convert to integers
	strs := strings.Fields(input)
	ABC := make([]int, len(strs))
	for i, str := range strs {
		num, err := strconv.Atoi(str)
		if err != nil {
			fmt.Println("NO")
			return
		}
		ABC[i] = num
	}

	// Count occurrences of the integer '5'
	count5 := 0
	for _, num := range ABC {
		if num == 5 {
			count5++
		}
	}

	// Check the conditions
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
