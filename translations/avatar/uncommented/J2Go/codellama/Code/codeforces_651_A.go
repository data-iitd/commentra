
package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	var a, b, c int
	fmt.Scan(&a, &b)
	if a == 1 && b == 1 {
		fmt.Println(0)
	} else {
		for a >= 1 || b >= 1 {
			if a >= b {
				b++
				a -= 2
			} else {
				a++
				b -= 2
			}
			if a <= 0 || b <= 0 {
				c++
				break
			}
			c++
		}
		fmt.Println(c)
	}
}

