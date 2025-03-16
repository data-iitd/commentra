
package main

import "fmt"

func main() {
	var n, m int
	fmt.Scan(&n, &m)
	l := make([][]string, n)
	for i := 0; i < n; i++ {
		s := make([]string, m)
		fmt.Scan(&s)
		for j := 0; j < m; j++ {
			if s[j] == "." {
				if (i+j)%2 == 0 {
					s[j] = "W"
				} else {
					s[j] = "B"
				}
			}
		}
		l[i] = s
	}
	for _, c := range l {
		fmt.Println(c)
	}
}

