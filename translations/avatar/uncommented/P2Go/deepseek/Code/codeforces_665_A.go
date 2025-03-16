package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var a, at int
	var b, bt int
	var t1, t2 int
	var st, fin, now, ans int

	fmt.Scan(&a, &at)
	fmt.Scan(&b, &bt)
	fmt.Scan(&t1, &t2)

	st = t2 + (t1 - 5) * 60
	fin = st + at
	now = 0
	ans = 0

	for now < fin && now < 1140 {
		if now + bt > st {
			ans += 1
		}
		now += b
	}

	fmt.Println(ans)
}

