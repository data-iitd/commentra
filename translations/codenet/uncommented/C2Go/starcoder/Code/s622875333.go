package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	for {
		var n, r int
		_, err := fmt.Scanf("%d %d", &n, &r)
		if err!= nil {
			break
		}
		a := make([]int, n)
		b := make([]int, n)
		for i := 0; i < n; i++ {
			a[i] = n - i
		}
		for i := 0; i < r; i++ {
			var p, c int
			_, err := fmt.Scanf("%d %d", &p, &c)
			if err!= nil {
				break
			}
			for j := 0; j < n; j++ {
				b[j] = a[j]
			}
			for j := 0; j < c; j++ {
				a[j] = b[p-1+j]
			}
			for j := c; j < c+p-1; j++ {
				a[j] = b[j-c]
			}
		}
		fmt.Printf("%d\n", a[0])
	}
}

