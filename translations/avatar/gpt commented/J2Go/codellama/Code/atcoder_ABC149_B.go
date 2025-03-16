package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Set up input reading from standard input with UTF-8 encoding
	reader := bufio.NewReader(os.Stdin)
	in := bufio.NewScanner(reader)
	in.Split(bufio.ScanLines)

	// Create an instance of Main class and pass the BufferedReader for input
	ins := new(Main)
	ins.readInput(in)

	// Perform calculations based on the input values
	ins.calc()

	// Display the results of the calculations
	ins.showResult()
}

// Main class to hold the values of A, B, K, and the results x, y
type Main struct {
	A, B, K int64
	x, y    int64
}

// Constructor to read input values A, B, and K from the BufferedReader
func (ins *Main) readInput(in *bufio.Scanner) {
	// Read a line of input, split it into tokens, and parse them as long integers
	tokens := strings.Split(in.Text(), " ")
	A, _ := strconv.ParseInt(tokens[0], 10, 64)
	B, _ := strconv.ParseInt(tokens[1], 10, 64)
	K, _ := strconv.ParseInt(tokens[2], 10, 64)

	// Assign the values to the instance variables
	ins.A = A
	ins.B = B
	ins.K = K
}

// Method to perform the main calculation based on A, B, and K
func (ins *Main) calc() {
	// Initialize x with the value of A and y with the value of B
	ins.x = ins.A
	ins.y = ins.B

	// Subtract K from A and assign the result to x
	ins.x = ins.A - ins.K

	// Check if the result x is negative
	if ins.x < 0 {
		// If x is negative, adjust y by adding the negative value of x to B
		ins.y = ins.B + ins.x
		// Set x to 0 since it cannot be negative
		ins.x = 0

		// Ensure y is not negative
		if ins.y < 0 {
			ins.y = 0
		}
	}
}

// Method to display the results of the calculations
func (ins *Main) showResult() {
	// Print the values of x and y
	fmt.Println(ins.x, ins.y)
}

// 