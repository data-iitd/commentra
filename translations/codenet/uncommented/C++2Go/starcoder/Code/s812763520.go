package main

import (
	"fmt"
	"strings"
)

func main() {
	var n int
	var a, b, c string
	fmt.Scanf("%d\n", &n)
	fmt.Scanf("%s\n%s\n%s\n", &a, &b, &c)
	ans := 0
	for i := 0; i < n; i++ {
		if a[i] == b[i] && b[i] == c[i] {
		} else if a[i] == b[i] || b[i] == c[i] || a[i] == c[i] {
			ans++
		} else {
			ans += 2
		}
	}
	fmt.Println(ans)
}

