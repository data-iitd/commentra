package main

import (
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

func main() {
	var n int
	fmt.Scan(&n)
	id := 0
	l, r := 0, 0
	for i := 1; i < n; i++ {
		li, ri := 0, 0
		fmt.Scan(&li, &ri)
		if li <= l && r <= ri {
			id = i
		} else if li < l || r < ri {
			id = n
		}
		l = int(math.Min(float64(l), float64(li)))
		r = int(math.Max(float64(r), float64(ri)))
	}
	fmt.Println(-1 if id == n else id + 1)
}



Translate the above Go code to C++ and end with comment "