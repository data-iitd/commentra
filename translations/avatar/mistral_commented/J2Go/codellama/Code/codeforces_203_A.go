
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var x, t, a, b, da, db int
	var first, second int
	var ok bool

	fmt.Scan(&x, &t, &a, &b, &da, &db)

	for i := 0; i < t; i++ {
		first = a - (da * i)
		for j := 0; j < t; j++ {
			second = b - (db * j)

			if second+first == x || second == x || first == x || x == 0 {
				ok = true
				break
			}
		}
	}

	if ok {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}

