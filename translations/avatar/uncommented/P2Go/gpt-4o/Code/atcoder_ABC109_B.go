package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)

	s := make(map[string]int)
	l := make([]string, n)

	for i := 0; i < n; i++ {
		fmt.Scan(&l[i])
	}

	f := "Yes"
	i := -1

	for _, v := range l {
		s[v]++
		if s[v] >= 2 {
			f = "No"
		}
		if i != -1 && l[i][len(l[i])-1] != v[0] {
			f = "No"
		}
		i++
	}

	fmt.Println(f)
}

// <END-OF-CODE>
