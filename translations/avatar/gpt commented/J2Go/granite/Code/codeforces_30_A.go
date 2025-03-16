
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Create a new instance of Main and call the solve method with a Scanner for input
	main := Main{}
	main.solve(bufio.NewScanner(os.Stdin))
}

type Main struct{}

func (m *Main) solve(sc *bufio.Scanner) {
	// Read three integers A, B, and n from the input
	A, B, n := m.nextInt(sc), m.nextInt(sc), m.nextInt(sc)

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
		if m.pow(x, n) == B {
			// If found, print the result considering the sign of B
			fmt.Println(m.sign(B) * x)
			return
		}
	}

	// If no valid x is found, print "No solution"
	fmt.Println("No solution")
}

func (m *Main) nextInt(sc *bufio.Scanner) int {
	sc.Scan()
	n, err := strconv.Atoi(sc.Text())
	if err!= nil {
		panic(err)
	}
	return n
}

func (m *Main) pow(x, n int) int {
	res := 1
	for i := 0; i < n; i++ {
		res *= x
	}
	return res
}

func (m *Main) sign(x int) int {
	if x < 0 {
		return -1
	} else {
		return 1
	}
}

