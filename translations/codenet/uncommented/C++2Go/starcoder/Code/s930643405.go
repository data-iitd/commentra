package main

import (
	"fmt"
	"math"
)

func main() {
	var n, k int
	fmt.Scanf("%d %d", &n, &k)
	d := make([]bool, 10)
	for i := 0; i < k; i++ {
		var a int
		fmt.Scanf("%d", &a)
		d[a] = true
	}
	for {
		hantei := true
		x := n
		for x > 0 {
			if d[x%10] {
				hantei = false
				break
			}
			x /= 10
		}
		if hantei {
			fmt.Println(n)
			break
		}
		n++
	}
}

