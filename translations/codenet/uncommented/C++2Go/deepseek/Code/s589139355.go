package main

import (
	"fmt"
	"strings"
)

func main() {
	var a int
	var t, h int
	var taro, hana string
	fmt.Scan(&a)

	for i := 0; i < a; i++ {
		fmt.Scan(&taro, &hana)
		lt := len(taro)
		lh := len(hana)
		var l int
		if lt > lh {
			l = lt
		} else {
			l = lh
		}
		tt := 0
		hh := 0

		if taro > hana {
			t += 3
		} else if hana > taro {
			h += 3
		} else if hana == taro {
			t += 1
			h += 1
		}
	}
	fmt.Println(t, h)
}

