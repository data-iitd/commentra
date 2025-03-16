package main

import (
	"fmt"
	"strings"
)

type Main struct{}

func (m *Main) compare(aa []rune, i int, bb []rune, j int, length int) int {
	for length > 0 {
		a := unicode.ToUpper(aa[i])
		b := unicode.ToUpper(bb[j])
		if a != b {
			return int(a) - int(b)
		}
		i++
		j++
		length--
	}
	return 0
}

func (m *Main) main() {
	var n int
	fmt.Scan(&n)
	ss := make([][]rune, n)

	for i := 0; i < n; i++ {
		var str string
		fmt.Scan(&str)
		ss[i] = []rune(str)
	}

	var cc string
	fmt.Scan(&cc)
	m := len(cc)

	var c rune
	fmt.Scanf("%c", &c)
	c_ := unicode.ToUpper(c)

	var a rune
	if c == 'a' {
		a = 'b'
	} else {
		a = 'a'
	}
	a_ := unicode.ToUpper(a)

	lucky := make([]bool, m)

	for j := 0; j < m; j++ {
		for i := 0; i < n; i++ {
			l := len(ss[i])
			if m-j >= l && m.compare([]rune(cc), j, ss[i], 0, l) == 0 {
				for h := 0; h < l; h++ {
					lucky[j+h] = true
				}
			}
		}
	}

	ccRunes := []rune(cc)
	for j := 0; j < m; j++ {
		if lucky[j] {
			if unicode.ToLower(ccRunes[j]) == c {
				if unicode.IsUpper(ccRunes[j]) {
					ccRunes[j] = a_
				} else {
					ccRunes[j] = a
				}
			} else {
				if unicode.IsUpper(ccRunes[j]) {
					ccRunes[j] = c_
				} else {
					ccRunes[j] = c
				}
			}
		}
	}

	fmt.Println(string(ccRunes))
}

func main() {
	o := Main{}
	o.main()
}

// <END-OF-CODE>
