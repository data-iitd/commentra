package main

import (
	"fmt"
	"os"
)

type Main struct {
	A, B, K, x, y int64
}

func main() {
	var ins Main
	ins.readInput()
	ins.calc()
	ins.showResult()
}

func (m *Main) readInput() {
	_, err := fmt.Scan(&m.A, &m.B, &m.K)
	if err != nil {
		fmt.Println("Error reading input:", err)
		os.Exit(1)
	}
}

func (m *Main) calc() {
	m.x = m.A
	m.y = m.B
	m.x = m.A - m.K
	if m.x < 0 {
		m.y = m.B + m.x
		m.x = 0
		if m.y < 0 {
			m.y = 0
		}
	}
}

func (m *Main) showResult() {
	fmt.Printf("%d %d\n", m.x, m.y)
}

// <END-OF-CODE>
