
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var (
	in  = bufio.NewReader(os.Stdin)
	out = bufio.NewWriter(os.Stdout)
)

func main() {
	x, y := readIntPair()
	ans := max(x+y-3+(y-x)%3 > 0, 0)
	fmt.Println(ans)
}

func readIntPair() (int, int) {
	s := readString()
	x, _ := strconv.Atoi(s[:strings.Index(s, " ")])
	y, _ := strconv.Atoi(s[strings.Index(s, " ")+1:])
	return x, y
}

func readString() string {
	s, _ := in.ReadString('\n')
	return strings.TrimSpace(s)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

