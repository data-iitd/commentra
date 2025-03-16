package main

import (
	"fmt"
)

func main() {
	var n, k int
	fmt.Scan(&n, &k)

	d := make([]bool, 10)
	for i := 0; i < k; i++ {
		var a int
		fmt.Scan(&a)
		d[a] = true
	}

	for {
		x := n
		hantei := true
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

// <END-OF-CODE>
