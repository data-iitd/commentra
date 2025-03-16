package main

import (
	"fmt"
	"strings"
)

func main() {
	var n, x int
	fmt.Scan(&n, &x)
	print(x, n)
}

func print(x, n int) {
	max := n*2 - 1
	if x == 1 || x == max {
		fmt.Println("No")
		return
	}
	fmt.Println("Yes")
	sep := "\n"
	var ans strings.Builder
	for i := x + n - 1; i < x+n+max; i++ {
		ans.WriteString(fmt.Sprintf("%d%s", (i%max+1), sep))
	}
	fmt.Println(ans.String())
}

