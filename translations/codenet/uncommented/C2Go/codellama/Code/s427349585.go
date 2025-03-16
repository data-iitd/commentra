
package main

import (
	"fmt"
)

type card struct {
	s byte
	v int
}

func main() {
	var n, i, v int
	var s string
	var stable bool
	var a, b [200000]card

	fmt.Scanf("%d", &n)

	for i = 0; i < n; i++ {
		fmt.Scanf("%s%d", &s, &v)
		a[i].s = b[i].s = s[0]
		a[i].v = b[i].v = v
	}

	//ms(a, n, 0, n)
	//qs(b, n, 0, n-1)

	for i = 0; i < n; i++ {
		if a[i].s != b[i].s {
			stable = false
		}
	}
	if stable {
		fmt.Println("Stable")
	} else {
		fmt.Println("Not stable")
	}
	for i = 0; i < n; i++ {
		fmt.Printf("%c %d\n", b[i].s, b[i].v)
	}
}

// 