package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type Main struct {
	A, B, K, x, y int64
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	ins := NewMain(reader)
	ins.calc()
	ins.showResult()
}

func NewMain(reader *bufio.Reader) *Main {
	line, _ := reader.ReadString('\n')
	tokens := strings.Fields(line)
	A, _ := strconv.ParseInt(tokens[0], 10, 64)
	B, _ := strconv.ParseInt(tokens[1], 10, 64)
	K, _ := strconv.ParseInt(tokens[2], 10, 64)

	return &Main{A: A, B: B, K: K}
}

func (m *Main) calc() {
	m.x = m.A
	m.y = m.B
	m.x = m.A - m.K // Subtract K from A to get the new value of x
	if m.x < 0 {
		m.y = m.B + m.x // Adjust B by the negative value of x
		m.x = 0        // Set x to 0 if it becomes negative
		if m.y < 0 {
			m.y = 0 // Set y to 0 if it becomes negative
		}
	}
}

func (m *Main) showResult() {
	fmt.Printf("%d %d\n", m.x, m.y) // Print the final values of x and y
}

// <END-OF-CODE>
