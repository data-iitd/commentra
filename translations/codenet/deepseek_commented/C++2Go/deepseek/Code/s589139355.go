package main

import (
	"fmt"
	"strings"
)

func main() {
	var a int
	fmt.Scan(&a)

	t, h := 0, 0

	for i := 0; i < a; i++ {
		var taro, hana string
		fmt.Scan(&taro, &hana)

		if strings.Compare(taro, hana) > 0 {
			t += 3
		} else if strings.Compare(hana, taro) > 0 {
			h += 3
		} else {
			t += 1
			h += 1
		}
	}

	fmt.Println(t, h)
}

