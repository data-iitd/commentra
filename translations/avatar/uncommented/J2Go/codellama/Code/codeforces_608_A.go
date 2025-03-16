
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var n, s int
	fmt.Scan(&n, &s)
	max := 0
	for i := 0; i < n; i++ {
		var f, t int
		fmt.Scan(&f, &t)
		if max < f+t {
			max = f + t
		}
	}
	fmt.Println(max, s)
}

