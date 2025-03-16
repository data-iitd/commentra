package main

import (
	"fmt"
)

func main() {
	var a, b, n int
	for {
		if _, err := fmt.Scanf("%d %d %d", &a, &b, &n); err != nil {
			break
		}
		a -= a / b * b
		sum := 0
		for i := 1; i <= n; i++ {
			a *= 10
			j := 9
			for j >= 0 {
				if b*j <= a {
					break
				}
				j--
			}
			a -= b * j
			sum += j
		}
		fmt.Println(sum)
	}
}

// <END-OF-CODE>
