package main

import (
	"fmt"
	"math"
	"strings"
)

func main() {
	var a, t, h, lt, lh, tt, hh, l int
	fmt.Scan(&a)
	var taro, hana string
	for i := 0; i < a; i++ {
		fmt.Scan(&taro, &hana)
		lt = len(taro)
		lh = len(hana)
		if lt > lh {
			l = lt
		} else {
			l = lh
		}
		tt = 0
		hh = 0

		if strings.Compare(taro, hana) > 0 {
			t = t + 3
		} else if strings.Compare(hana, taro) > 0 {
			h = h + 3
		} else if strings.Compare(hana, taro) == 0 {
			h = h + 1
			t = t + 1
		}
	}
	fmt.Println(t, h)
}

