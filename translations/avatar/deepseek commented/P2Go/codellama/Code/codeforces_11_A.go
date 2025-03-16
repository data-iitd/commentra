
package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var n, d int
	fmt.Scan(&n, &d)
	x := make([]int, n)
	m := 0
	q := 0
	fmt.Scan(&x)
	for i := 0; i < len(x); i++ {
		x[i], _ = strconv.Atoi(strings.Split(x, " ")[i])
	}
	for a := 0; a < len(x)-1; a++ {
		if x[a] >= x[a+1] {
			q = int((x[a] - x[a+1]) / d)
			m = m + q
			x[a+1] = x[a+1] + q*d
		}
	}
	fmt.Println(m)
}

