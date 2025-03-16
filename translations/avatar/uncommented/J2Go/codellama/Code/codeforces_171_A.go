
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	var n, m int
	sc.Scan()
	n, _ = strconv.Atoi(sc.Text())
	sc.Scan()
	m, _ = strconv.Atoi(sc.Text())
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

