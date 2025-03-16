package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
	"unicode"
)

type Main struct {
	scanner *bufio.Scanner
}

func NewMain() *Main {
	return &Main{scanner: bufio.NewScanner(os.Stdin)}
}

func (m *Main) compare(aa []rune, i int, bb []rune, j int, length int) int {
	for k := 0; k < length; k++ {
		a := unicode.ToUpper(aa[i])
		b := unicode.ToUpper(bb[j])
		if a != b {
			return int(a) - int(b)
		}
		i++
		j++
	}
	return 0
}

func (m *Main) mainLogic() {
	m.scanner.Scan()
	n := 0
	fmt.Sscanf(m.scanner.Text(), "%d", &n)

	ss := make([][]rune, n)
	for i := 0; i < n; i++ {
		m.scanner.Scan()
		ss[i] = []rune(m.scanner.Text())
	}

	m.scanner.Scan()
	cc := []rune(m.scanner.Text())
	m.scanner.Scan()
	c := []rune(m.scanner.Text())[0]
	c_ := unicode.ToUpper(c)
	var a rune
	if c == 'a' {
		a = 'b'
	} else {
		a = 'a'
	}
	a_ := unicode.ToUpper(a)

	m := len(cc)
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
			if unicode.ToLower(cc[j]) == c {
				if unicode.IsUpper(cc[j]) {
					cc[j] = a_
				} else {
					cc[j] = a
				}
			} else {
				if unicode.IsUpper(cc[j]) {
					cc[j] = c_
				} else {
					cc[j] = c
				}
			}
		}
	}

	fmt.Println(string(cc))
}

func main() {
	o := NewMain()
	o.mainLogic()
}

// <END-OF-CODE>
