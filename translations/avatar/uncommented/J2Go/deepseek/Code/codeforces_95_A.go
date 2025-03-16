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
}

func (m *Main) compare(aa, bb []rune, i, j, m int) int {
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
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	scanner.Scan()
	n := parseInt(scanner.Text())
	ss := make([][]rune, n)
	for i := 0; i < n; i++ {
		scanner.Scan()
		ss[i] = []rune(scanner.Text())
	}
	scanner.Scan()
	cc := []rune(scanner.Text())
	scanner.Scan()
	m := len(cc)
	c := []rune(scanner.Text())[0]
	c_ := unicode.ToUpper(rune(c))
	a := c == 'a' ? 'b' : 'a'
	a_ := unicode.ToUpper(rune(a))
	lucky := make([]bool, m)
	for j := 0; j < m; j++ {
		for i := 0; i < n; i++ {
			l := len(ss[i])
			if m-j >= l && m.compare(cc, ss[i], j, 0, l) == 0 {
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
	m.out.WriteString(string(cc))
	m.out.Flush()
}

func parseInt(s string) int {
	var result int
	for _, c := range s {
		result = result*10 + int(c-'0')
	}
	return result
}

func main() {
	m := &Main{out: bufio.NewWriter(os.Stdout)}
	m.main()
}

