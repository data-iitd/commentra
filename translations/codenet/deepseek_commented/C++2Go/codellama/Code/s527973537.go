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
	for i := 0; i < len(N); i++ {
		S += int(N[i] - '0')
	}

	// Step 5: Check if the number is divisible by the sum of its digits
	if stoi(N)%S == 0 {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}

	// Step 6: Return 0
	return
}

func stoi(s string) int {
	i, _ := strconv.Atoi(s)
	return i
}

