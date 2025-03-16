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

func (m *Main) Println(cc []rune) {
	for _, c := range cc {
		fmt.Fprint(m.out, string(c))
	}
	fmt.Fprintln(m.out)
}

func main() {
	m := &Main{out: bufio.NewWriter(os.Stdout)}
	defer m.out.Flush()
	m.main()
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
	c := []rune(scanner.Text())[0]
	c_ := unicode.ToUpper(c)
	a := 'a'
	if c == 'a' {
		a = 'b'
	}
	a_ := unicode.ToUpper(a)
	m_ := len(cc)
	lucky := make([]bool, m_)
	for j := 0; j < m_; j++ {
		for i := 0; i < n; i++ {
			l := len(ss[i])
			if m_ >= j+l && m.Compare(cc, i, j, 0, l) == 0 {
				for h := 0; h < l; h++ {
					lucky[j+h] = true
				}
			}
		}
	}
	for j := 0; j < m_; j++ {
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
	m.Println(cc)
}

func parseInt(s string) int {
	var result int
	for _, c := range s {
		result = result*10 + int(c-'0')
	}
	return result
}

