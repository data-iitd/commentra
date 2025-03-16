package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	for {
		var a, b, n int
		_, err := fmt.Scanf("%d %d %d", &a, &b, &n)
		if err == os.EOF {
			break
		}
		a -= a / b * b
		sum := 0
		for i := 1; i <= n; i++ {
			a *= 10
			for j := 9; j >= 0; j-- {
				if b*j <= a {
					break
				}
			}
			a -= b * j
			sum += j
		}
		fmt.Println(sum)
	}
}

