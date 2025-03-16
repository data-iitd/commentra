package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var n, m, s, f int
	fmt.Scan(&n, &m, &s, &f)

	var d int
	var c string
	if s < f {
		d = 1
		c = "R"
	} else {
		d = -1
		c = "L"
	}

	res := ""
	i := 1
	j := s
	var t, l, r int
	k := 1

	// Read the first t, l, r
	fmt.Scan(&t, &l, &r)

	for j != f {
		if i > t && k < m {
			fmt.Scan(&t, &l, &r)
			k++
		}
		if i == t && (l <= j && j <= r || l <= j+d && j+d <= r) {
			res += "X"
		} else {
			res += c
			j += d
		}
		i++
	}
	fmt.Println(res)
}

// <END-OF-CODE>
