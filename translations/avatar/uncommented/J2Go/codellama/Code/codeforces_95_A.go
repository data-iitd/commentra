
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
	var n int
	sc.Scan()
	n, _ = strconv.Atoi(sc.Text())
	ss := make([][]rune, n)
	for i := 0; i < n; i++ {
		sc.Scan()
		ss[i] = []rune(sc.Text())
	}
	sc.Scan()
	cc := []rune(sc.Text())
	m := len(cc)
	c := rune(sc.Text()[0])
	c_ := rune(strings.ToUpper(string(c)))
	a := rune('a')
	a_ := rune(strings.ToUpper(string(a)))
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
			if c == 'a' {
				cc[j] = a_
			} else {
				cc[j] = c_
			}
		}
	}
	fmt.Println(string(cc))
}

func compare(aa []rune, i int, bb []rune, j int, m int) int {
	for m > 0 {
		a := rune(strings.ToUpper(string(aa[i])))
		b := rune(strings.ToUpper(string(bb[j])))
		if a != b {
			return int(a - b)
		}
		i++
		j++
		m--
	}
	return 0
}

