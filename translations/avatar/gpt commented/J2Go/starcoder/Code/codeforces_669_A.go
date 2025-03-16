package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Creating a new buffered reader to read input from the console
	reader := bufio.NewReader(os.Stdin)

	// Reading an integer input from the user
	input, _ := reader.ReadString('\n')
	n, _ := strconv.Atoi(strings.TrimSpace(input))

	// Calling the solve method with the input integer
	solve(n)
}

func solve(n int) {
	// Calculating and printing the result based on the input integer n
	// The formula calculates (n / 3) * 2 and adds 1 if n is not divisible by 3
	fmt.Println((n / 3) * 2 + (n % 3 == 0? 0 : 1))
}

