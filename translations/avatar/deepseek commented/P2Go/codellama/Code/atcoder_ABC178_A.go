
package main

import (
	"fmt"
	"os"
	"strconv"
)

func solve(tc int) {
	a, _ := strconv.Atoi(os.Args[tc])
	fmt.Println(1, a == 0)
}

func main() {
	tcs := 1
	tc := 1
	for tc <= tcs {
		solve(tc)
		tc++
	}
}

