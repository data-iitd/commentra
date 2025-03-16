package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

type Main struct {
	A, B, K, x, y int64
}

func main() {
	reader := bufio.NewReader(os.Stdin) // Creating a buffered reader to read from standard input
	ins := Main{}                          // Creating an instance of the Main struct
	ins.init(reader)                       // Initializing the struct with input values
	ins.calc()                             // Calling the calc method to perform calculations
	ins.showResult()                       // Calling the showResult method to display the results
}

func (m *Main) init(reader *bufio.Reader) { // Method to initialize the struct with input values
	line, _ := reader.ReadString('\n') // Reading a line of input
	tokens := bufio.NewScanner(bufio.NewReaderString(line)) // Creating a scanner to split the line
	tokens.Split(bufio.ScanWords) // Setting the scanner to split by whitespace

	tokens.Scan() // Scanning the first token
	m.A, _ = strconv.ParseInt(tokens.Text(), 10, 64) // Parsing the first token into A
	tokens.Scan() // Scanning the second token
	m.B, _ = strconv.ParseInt(tokens.Text(), 10, 64) // Parsing the second token into B
	tokens.Scan() // Scanning the third token
	m.K, _ = strconv.ParseInt(tokens.Text(), 10, 64) // Parsing the third token into K
}

func (m *Main) calc() { // Method to perform calculations
	m.x = m.A // Assigning the value of A to x
	m.y = m.B // Assigning the value of B to y

	m.x = m.A - m.K // Subtracting K from A and assigning the result to x

	if m.x < 0 { // Checking if x is negative
		m.y = m.B + m.x // If x is negative, adding the absolute value of x to B and assigning the result to y
		m.x = 0 // Setting x to zero
	}

	if m.y < 0 { // Checking if y is negative
		m.y = 0 // If y is negative, setting it to zero
	}
}

func (m *Main) showResult() { // Method to display the results
	fmt.Printf("%d %d\n", m.x, m.y) // Printing the values of x and y separated by a space character
}

// <END-OF-CODE>
