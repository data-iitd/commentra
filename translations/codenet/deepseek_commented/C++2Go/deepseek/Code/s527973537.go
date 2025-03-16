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
	for _, char := range N {
		S += int(char - '0')
	}

	// Step 5: Check if the number is divisible by the sum of its digits
	num, _ := strconv.Atoi(N)
	if num % S == 0 {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}

	// Step 6: Return 0
}

