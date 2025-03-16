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
		var input string
		fmt.Scan(&input)
		ss[i] = []rune(input)
	}

	var ccInput string
	fmt.Scan(&ccInput)
	cc := []rune(ccInput)
	mLength := len(cc)

	var c rune
	fmt.Scanf("%c\n", &c)
	cUpper := unicode.ToUpper(c)
	a := 'a'
	if c == 'a' {
		a = 'b'
	}
	aUpper := unicode.ToUpper(a)

	lucky := make([]bool, mLength)

	for j := 0; j < mLength; j++ {
		for i := 0; i < n; i++ {
			l := len(ss[i])
			if mLength-j >= l && m.compare(cc, j, ss[i], 0, l) == 0 {
				for h := 0; h < l; h++ {
					lucky[j+h] = true
				}
			}
		}
	}

	for j := 0; j < mLength; j++ {
		if lucky[j] {
			if unicode.ToLower(cc[j]) == unicode.ToLower(c) {
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

	fmt.Println(string(cc))
}

func main() {
	o := Main{}
	o.main()
}

// <END-OF-CODE>
