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
	var a, b, c, d int
	fmt.Fscan(reader, &a, &b, &c, &d)
	if c > b {
		fmt.Println(0)
	} else if a > d {
		fmt.Println(0)
	} else if a < c {
		fmt.Println(min(b, d) - c)
	} else {
		l := []int{a, b, c, d}
		sort.Ints(l)
		fmt.Println(l[2] - l[1])
	}
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

