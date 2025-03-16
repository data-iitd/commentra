package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	new Main().run()
}

type Main struct {
	br   *bufio.Reader
	out  *os.File
	st   *strings.Tokenizer
}

func (m *Main) run() {
	m.br = bufio.NewReader(os.Stdin)
	m.out = os.Stdout
	m.solve()
	m.br.Close()
	m.out.Close()
}

func (m *Main) solve() {
	x := m.nextInt()
	t := m.nextInt()
	a := m.nextInt()
	b := m.nextInt()
	da := m.nextInt()
	db := m.nextInt()
	ok := false
	for i := 0; i < t; i++ {
		first := a - (da * i)
		for j := 0; j < t; j++ {
			second := b - (db * j)
			if second+first == x || second == x || first == x || x == 0 {
				ok = true
				break
			}
		}
		if ok {
			break
		}
	}
	if ok {
		fmt.Fprint(m.out, "YES")
	} else {
		fmt.Fprint(m.out, "NO")
	}
}

func (m *Main) nextInt() int {
	return parseInt(m.next())
}

func (m *Main) next() string {
	for m.st == nil || !m.st.Scan() {
		line, err := m.br.ReadString('\n')
		if err != nil {
			fmt.Println("END_OF_FILE")
			return "END_OF_FILE"
		}
		m.st = strings.NewTokenizer(line)
	}
	return m.st.Token()
}

func parseInt(s string) int {
	i, err := strconv.Atoi(s)
	if err != nil {
		fmt.Println("Error parsing int:", err)
		return 0
	}
	return i
}

