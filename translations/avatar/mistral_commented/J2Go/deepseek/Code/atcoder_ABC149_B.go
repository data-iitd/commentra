package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	parts := strings.Split(strings.TrimSpace(input), " ")

	A, _ := strconv.ParseInt(parts[0], 10, 64)
	B, _ := strconv.ParseInt(parts[1], 10, 64)
	K, _ := strconv.ParseInt(parts[2], 10, 64)

	ins := NewMain(A, B, K)
	ins.Calc()
	ins.ShowResult()
}

type Main struct {
	A, B, K int64
	x, y    int64
}

func NewMain(A, B, K int64) *Main {
	return &Main{A: A, B: B, K: K}
}

func (m *Main) Calc() {
	m.x = m.A - m.K
	if m.x < 0 {
		m.y = m.B + m.x
		m.x = 0
	}
	if m.y < 0 {
		m.y = 0
	}
}

func (m *Main) ShowResult() {
	fmt.Println(m.x, m.y)
}

