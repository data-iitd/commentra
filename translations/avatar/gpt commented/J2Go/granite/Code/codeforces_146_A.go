
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	var n int
	fmt.Fscanf(reader, "%d\n", &n)

	var s string
	fmt.Fscanf(reader, "%s\n", &s)

	var t int
	for _, c := range s {
		if c!= '4' && c!= '7' {
			t = 1
		}
	}

	if t == 1 {
		fmt.Println("NO")
	} else {
		var x, y int
		for i, c := range s[:n/2] {
			x += int(c - '0')
		}
		for i, c := range s[n/2:] {
			y += int(c - '0')
		}
		if x == y {
			fmt.Println("YES")
		} else {
			fmt.Println("NO")
		}
	}
}

