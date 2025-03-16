
package main

import (
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

func main() {
	var n int
	var str string
	var t int
	var x int
	var y int

	fmt.Scan(&n)
	fmt.Scan(&str)

	l := strings.Split(str, "")

	for i := 0; i < n; i++ {
		if l[i] != "4" && l[i] != "7" {
			t = 1
		}
	}

	if t == 1 {
		fmt.Println("NO")
	} else {
		for i := 0; i < n/2; i++ {
			x = x + strconv.Atoi(l[i])
		}
		for i := n - 1; i > (n/2)-1; i-- {
			y = y + strconv.Atoi(l[i])
		}
		if x == y {
			fmt.Println("YES")
		} else {
			fmt.Println("NO")
		}
	}
}

