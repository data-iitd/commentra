package main

import (
	"fmt"
	"strconv"
)

func main() {
	// Step 3: Input a string
	var N string
	fmt.Scan(&N)

	// Step 4: Calculate the sum of digits
	S := 0
	for _, ch := range N {
		digit, _ := strconv.Atoi(string(ch))
		S += digit
	}

	// Step 5: Check if the number is divisible by the sum of its digits
	num, _ := strconv.Atoi(N)
	if num%S == 0 {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}

	// Step 6: Return 0 (implicit in Go)
}

// <END-OF-CODE>
