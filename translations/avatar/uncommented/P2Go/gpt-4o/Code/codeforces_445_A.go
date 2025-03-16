package main

import (
	"fmt"
)

func main() {
	var n, m int
	fmt.Scan(&n, &m)

	l := make([][]rune, n)
	for i := 0; i < n; i++ {
		var s string
		fmt.Scan(&s)
		row := make([]rune, m)
		for j, char := range s {
			if char == '.' {
				if (i+j)%2 == 1 {
					row[j] = 'W'
				} else {
					row[j] = 'B'
				}
			} else {
				row[j] = char
			}
		}
		l[i] = row
	}

	for _, c := range l {
		fmt.Println(string(c))
	}
}

// <END-OF-CODE>
