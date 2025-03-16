
package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	sc.Scan()
	n, _ := sc.Int()
	ss := make([][]rune, n)
	for i := 0; i < n; i++ {
		ss[i] = []rune(sc.Text())
		sc.Scan()
	}
	cc := []rune(sc.Text())
	m := len(cc)
	c, _ := sc.Next()
	c_ := strings.ToUpper(c)
	a := 'a'
	if c == 'a' {
		a = 'b'
	}
	a_ := strings.ToUpper(string(a))
	lucky := make([]bool, m)
	for j := 0; j < m; j++ {
		for i := 0; i < n; i++ {
			l := len(ss[i])
			if m-j >= l && compare(cc, j, ss[i], 0, l) == 0 {
				for h := 0; h < l; h++ {
					lucky[j+h] = true
				}
			}
		}
	}
	for j := 0; j < m; j++ {
		if lucky[j] {
			if strings.ToLower(string(cc[j])) == c {
				cc[j] = rune(strings.ToUpper(string(cc[j])) == a_)
			} else {
				cc[j] = rune(strings.ToUpper(string(cc[j])) == c_)
			}
		}
	}
	fmt.Println(string(cc))
}

func compare(aa, bb []rune, i, j, m int) int {
	for m > 0 {
		a := strings.ToUpper(string(aa[i]))
		b := strings.ToUpper(string(bb[j]))
		if a!= b {
			return int(a[0] - b[0])
		}
		i++
		j++
		m--
	}
	return 0
}

