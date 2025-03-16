package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type Main struct {
	A, B, K int64
	x, y    int64
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	input := bufio.NewScanner(os.Stdin)
	input.Split(bufio.ScanWords)
	var ins Main
	ins.read(reader, input)
	ins.calc()
	ins.showResult()
}

func (m *Main) read(reader *bufio.Reader, input *bufio.Scanner) {
	input.Scan()
	parts := strings.Split(input.Text(), " ")
	m.A, _ = strconv.ParseInt(parts[0], 10, 64)
	m.B, _ = strconv.ParseInt(parts[1], 10, 64)
	m.K, _ = strconv.ParseInt(parts[2], 10, 64)
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
	fmt.Println(m.x, m.y)
}

