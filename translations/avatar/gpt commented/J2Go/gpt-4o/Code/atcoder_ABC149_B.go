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
	// Set up input reading from standard input
	reader := bufio.NewReader(os.Stdin)

	// Create an instance of Main and read input values
	ins := Main{}
	ins.readInput(reader)

	// Perform calculations based on the input values
	ins.calc()

	// Display the results of the calculations
	ins.showResult()
}

// Method to read input values A, B, and K from the BufferedReader
func (m *Main) readInput(reader *bufio.Reader) {
	line, _ := reader.ReadString('\n')
	tokens := bufio.NewScanner(bufio.NewReaderString(line))
	tokens.Split(bufio.ScanWords)

	tokens.Scan()
	m.A, _ = strconv.ParseInt(tokens.Text(), 10, 64)
	tokens.Scan()
	m.B, _ = strconv.ParseInt(tokens.Text(), 10, 64)
	tokens.Scan()
	m.K, _ = strconv.ParseInt(tokens.Text(), 10, 64)
}

// Method to perform the main calculation based on A, B, and K
func (m *Main) calc() {
	m.x = m.A - m.K

	if m.x < 0 {
		m.y = m.B + m.x
		m.x = 0

		if m.y < 0 {
			m.y = 0
		}
	} else {
		m.y = m.B
	}
}

// Method to display the results of the calculations
func (m *Main) showResult() {
	fmt.Printf("%d %d\n", m.x, m.y)
}

// <END-OF-CODE>
