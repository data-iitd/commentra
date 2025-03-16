package main

import (
	"fmt"
)

func main() {
	var a, at int
	var b, bt int
	var t1, t2 int

	fmt.Scan(&a, &at)
	fmt.Scan(&b, &bt)
	fmt.Scanf("%d:%d", &t1, &t2)

	st := t2 + (t1-5)*60
	fin := st + at
	now := 0
	ans := 0

	for now < fin && now < 1140 {
		if now+bt > st {
			ans++
		}
		now += b
	}
	fmt.Println(ans)
}

// <END-OF-CODE>
