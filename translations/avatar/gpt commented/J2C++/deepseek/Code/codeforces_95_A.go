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

func (m *Main) Println(a []rune) {
	for _, r := range a {
		m.out.WriteRune(r)
	}
	m.out.WriteByte('\n')
}

func (m *Main) main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)

	// Read the number of strings
	sc.Scan()
	n := parseInt(sc.Text())
	ss := make([][]rune, n)

	// Read each string and convert it to a rune slice
	for i := 0; i < n; i++ {
		sc.Scan()
		ss[i] = []rune(sc.Text())
	}

	// Read the character array to be modified
	sc.Scan()
	cc := []rune(sc.Text())
	m := len(cc)

	// Read the character to be replaced
	sc.Scan()
	c := []rune(sc.Text())[0]
	c_ := unicode.ToUpper(c)

	// Determine the character to replace with
	var a rune
	if c == 'a' {
		a = 'b'
	} else {
		a = 'a'
	}
	a_ := unicode.ToUpper(a)

	// Array to track positions that can be marked as lucky
	lucky := make([]bool, m)

	// Loop through each position in the character array
	for j := 0; j < m; j++ {
		for i := 0; i < n; i++ {
			l := len(ss[i])
			// Check if the substring matches and mark lucky positions
			if m-j >= l && compare(cc[j:], ss[i], 0, l) == 0 {
				for h := 0; h < l; h++ {
					lucky[j+h] = true
				}
			}
		}
	}

	// Replace characters in the original array based on lucky positions
	for j := 0; j < m; j++ {
		if lucky[j] {
			// Replace with the determined character based on case
			if unicode.ToLower(cc[j]) == unicode.ToLower(c) {
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

	// Print the modified character array
	m.Println(cc)
}

func compare(aa []rune, bb []rune, i, j, m int) int {
	for m > 0 {
		// Convert characters to uppercase for comparison
		a := unicode.ToUpper(aa[i])
		b := unicode.ToUpper(bb[j])
		// Return the difference if characters do not match
		if a != b {
			return int(a) - int(b)
		}
		i++
		j++
		m--
	}
	// Return 0 if all characters match
	return 0
}

func parseInt(s string) int {
	var res int
	for _, c := range s {
		res = res*10 + int(c-'0')
	}
	return res
}

func main() {
	m := &Main{out: bufio.NewWriter(os.Stdout)}
	defer m.out.Flush()
	m.main()
}
