
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var n int
	fmt.Scan(&n)

	for i := 0; i < n; i++ {
		var f, t int
		fmt.Scan(&f, &t)

		var max int
		if max < f+t {
			max = f + t
		}
	}

	fmt.Println(max)
}

