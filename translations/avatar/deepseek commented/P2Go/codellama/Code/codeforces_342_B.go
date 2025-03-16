
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

	var res string
	var i, j int
	var t, l, r int
	var k int
	fmt.Scan(&t, &l, &r)
	k = 1

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

// 