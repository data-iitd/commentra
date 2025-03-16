package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a new instance of Main and call the solve method with a bufio.Reader for input
	main := Main{}
	main.solve(bufio.NewReader(os.Stdin))
}

type Main struct {
}

func (this *Main) solve(reader *bufio.Reader) {
	// Read three integers A, B, and n from the input
	A, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	B, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	n, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))

	// Check if A is zero
	if A == 0 {
		// If both A and B are zero, print 1 (indeterminate case)
		if B == 0 {
			fmt.Println(1)
		} else {
			// If A is zero and B is not, print "No solution"
			fmt.Println("No solution")
		}
		return
	}

	// Check if B is not divisible by A
	if B%A!= 0 {
		// If B is not divisible by A, print "No solution"
		fmt.Println("No solution")
		return
	}

	// Divide B by A to simplify the equation
	B /= A

	// Determine if B is negative
	neg := B < 0

	// Check if B is negative and n is even
	if neg && n%2 == 0 {
		// If both conditions are true, print "No solution"
		fmt.Println("No solution")
		return
	}

	// If B is negative, make it positive for further calculations
	if neg {
		B = -B
	}

	// Iterate through possible values of x from 0 to B
	for x := 0; x <= B; x++ {
		// Check if x raised to the power of n equals B
		if int(math.Pow(float64(x), float64(n))) == B {
			// If found, print the result considering the sign of B
			fmt.Println(neg*-x)
			return
		}
	}

	// If no valid x is found, print "No solution"
	fmt.Println("No solution")
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}

	return strings.TrimRight(string(str), "\r\n")
}

