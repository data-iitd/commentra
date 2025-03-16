package main

import (
	"fmt"
)

func main() {
	var a int
	var t, h int
	fmt.Scan(&a)

	for i := 0; i < a; i++ {
		var taro, hana string
		fmt.Scan(&taro, &hana)

		lt := len(taro)
		lh := len(hana)
		var l int
		if lt > lh {
			l = lt
		} else {
			l = lh
		}

		if taro > hana {
			t += 3
		} else if hana > taro {
			h += 3
		} else if hana == taro {
			h++
			t++
		}
	}
	fmt.Println(t, h)
}

// <END-OF-CODE>
