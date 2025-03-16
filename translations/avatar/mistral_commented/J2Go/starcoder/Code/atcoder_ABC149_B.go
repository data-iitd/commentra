
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
}

func (m *Main) calc() {
	m.x = m.A
	m.y = m.B

	m.x -= m.K

	if m.x < 0 {
		m.y += m.x
		m.x = 0
	}

	if m.y < 0 {
		m.y = 0
	}
}

func (m *Main) showResult() {
	fmt.Println(m.x, m.y)
}

func main() {
	in := bufio.NewReader(os.Stdin)
	m := Main{}

	line, _ := in.ReadString('\n')
	tokens := strings.Split(line, " ")
	m.A, _ = strconv.ParseInt(tokens[0], 10, 64)
	m.B, _ = strconv.ParseInt(tokens[1], 10, 64)
	m.K, _ = strconv.ParseInt(tokens[2], 10, 64)

	m.calc()
	m.showResult()
}

