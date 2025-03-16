
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	var n, m int
	scanner.Scan()
	n, _ = strconv.Atoi(scanner.Text())
	scanner.Scan()
	m, _ = strconv.Atoi(scanner.Text())
	t := reverse(m)
	fmt.Println(t + n)
}

func reverse(n int) int {
	if n < 10 {
		return n * 10
	}
	t := n
	r := 0
	for t > 0 {
		r = r*10 + t%10
		t = t / 10
	}
	return r
}

// 