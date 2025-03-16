package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Set up input reading from standard input
	reader := bufio.NewReader(os.Stdin)
	
	// Read a line of input
	input, _ := reader.ReadString('\n')
	
	// Trim the input and split it into tokens
	tokens := strings.Split(strings.TrimSpace(input), " ")
	
	// Parse the tokens as integers
	A, _ := strconv.ParseInt(tokens[0], 10, 64)
	B, _ := strconv.ParseInt(tokens[1], 10, 64)
	K, _ := strconv.ParseInt(tokens[2], 10, 64)
	
	// Create an instance of Main and pass the reader for input
	ins := NewMain(A, B, K, reader)
	
	// Perform calculations based on the input values
	ins.Calc()
	
	// Display the results of the calculations
	ins.ShowResult()
}

// Main struct to hold the values of A, B, K, and the results x, y
type Main struct {
	A, B, K int64
	x, y    int64
	reader  *bufio.Reader
}

// Constructor to read input values A, B, and K from the reader
func NewMain(A, B, K int64, reader *bufio.Reader) *Main {
	return &Main{A: A, B: B, K: K, reader: reader}
}

// Method to perform the main calculation based on A, B, and K
func (ins *Main) Calc() {
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
func (ins *Main) ShowResult() {
	// Print the values of x and y
	fmt.Println(ins.x, ins.y)
}
