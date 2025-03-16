package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
	"unicode"
)

type Main struct {
	out *bufio.Writer
	sc  *bufio.Scanner
}

func NewMain() *Main {
	return &Main{
		out: bufio.NewWriter(os.Stdout),
		sc:  bufio.NewScanner(os.Stdin),
	}
}

func (m *Main) Flush() {
	m.out.Flush()
}

func (m *Main) Println(a []rune) {
	for _, r := range a {
		m.out.WriteRune(r)
	}
	m.out.WriteByte('\n')
}

func (m *Main) Compare(aa, bb []rune, i, j, m int) int {
	for m > 0 {
		a := unicode.ToUpper(aa[i])
		b := unicode.ToUpper(bb[j])
		if a != b {
			return int(a) - int(b)
		}
		i++
		j++
		m--
	}
	return 0
}

func (m *Main) main() {
	// Reading the number of strings and the array of strings
	var n int
	fmt.Fscan(m.sc, &n)
	ss := make([][]rune, n)
	for i := 0; i < n; i++ {
		m.sc.Scan()
		ss[i] = []rune(m.sc.Text())
	}

	// Reading the pattern array and the target character
	m.sc.Scan()
	cc := []rune(m.sc.Text())
	m.sc.Scan()
	c := rune(m.sc.Text()[0])
	cUpper := unicode.ToUpper(c)
	a := 'a'
	if c == 'a' {
		a = 'b'
	}
	aUpper := unicode.ToUpper(a)

	// Array to mark positions in cc that match any string in ss
	lucky := make([]bool, len(cc))

	// Finding lucky positions and updating characters based on the target character c
	for j := 0; j < len(cc); j++ {
		for i := 0; i < n; i++ {
			l := len(ss[i])
			if len(cc)-j >= l && m.Compare(cc, ss[i], j, 0, l) == 0 {
				for h := 0; h < l; h++ {
					lucky[j+h] = true
				}
			}
		}
	}

	// Updating characters in cc based on the lucky positions and target character c
	for j := 0; j < len(cc); j++ {
		if lucky[j] {
			if unicode.ToLower(cc[j]) == c {
				if unicode.IsUpper(cc[j]) {
					cc[j] = aUpper
				} else {
					cc[j] = a
				}
			} else {
				if unicode.IsUpper(cc[j]) {
					cc[j] = cUpper
				} else {
					cc[j] = c
				}
			}
		}
	}

	// Printing the modified cc array
	m.Println(cc)
}

func main() {
	m := NewMain()
	defer m.Flush()
	m.main()
}

