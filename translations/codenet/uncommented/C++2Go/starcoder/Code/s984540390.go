package main

import (
	"fmt"
	"math"
)

func main() {
	var h int64
	fmt.Scanf("%d", &h)
	ans := int64(0)
	cnt := int64(1)
	for h!= 1 {
		if h%2!= 0 {
			h--
		}
		h /= 2
		ans += cnt
		cnt *= 2
	}
	fmt.Printf("%d\n", ans+1)
}

