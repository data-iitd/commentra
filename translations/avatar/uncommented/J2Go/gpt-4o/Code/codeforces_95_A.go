package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

type Main struct {
	scanner *bufio.Scanner
}

func NewMain() *Main {
	return &Main{scanner: bufio.NewScanner(os.Stdin)}
}

func (m *Main) compare(aa []rune, i int, bb []rune, j int, length int) int {
	for k := 0; k < length; k++ {
		a := toUpper(aa[i])
		b := toUpper(bb[j])
		if a != b {
			return int(a) - int(b)
		}
		i++
		j++
	}
	return 0
}

func toUpper(r rune) rune {
	if r >= 'a' && r <= 'z' {
		return r - 'a' + 'A'
	}
	return r
}

func (m *Main) run() {
	m.scanner.Scan()
	n := toInt(m.scanner.Text())
	ss := make([][]rune, n)

	for i := 0; i < n; i++ {
		m.scanner.Scan()
		ss[i] = []rune(m.scanner.Text())
	}

	m.scanner.Scan()
	cc := []rune(m.scanner.Text())
	m := len(cc)

	m.scanner.Scan()
	c := []rune(m.scanner.Text())[0]
	c_ := toUpper(c)
	var a rune
	if c == 'a' {
		a = 'b'
	} else {
		a = 'a'
	}
	a_ := toUpper(a)

	lucky := make([]bool, m)

	for j := 0; j < m; j++ {
		for i := 0; i < n; i++ {
			l := len(ss[i])
			if m-j >= l && m.compare(cc, j, ss[i], 0, l) == 0 {
				for h := 0; h < l; h++ {
					lucky[j+h] = true
				}
			}
		}
	}

	for j := 0; j < m; j++ {
		if lucky[j] {
			if toLower(cc[j]) == c {
				if isUpper(cc[j]) {
					cc[j] = a_
				} else {
					cc[j] = a
				}
			} else {
				if isUpper(cc[j]) {
					cc[j] = c_
				} else {
					cc[j] = c
				}
			}
		}
	}

	fmt.Println(string(cc))
}

func toInt(s string) int {
	var n int
	fmt.Sscanf(s, "%d", &n)
	return n
}

func toLower(r rune) rune {
	if r >= 'A' && r <= 'Z' {
		return r - 'A' + 'a'
	}
	return r
}

func isUpper(r rune) bool {
	return r >= 'A' && r <= 'Z'
}

func main() {
	o := NewMain()
	o.run()
}

// <END-OF-CODE>
