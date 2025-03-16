
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
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()
	var n int
	sc.Scan()
	n, _ = strconv.Atoi(sc.Text())
	g := make([][]int, n)
	for i := 0; i < n-1; i++ {
		sc.Scan()
		s := strings.Split(sc.Text(), " ")
		a, _ := strconv.Atoi(s[0])
		b, _ := strconv.Atoi(s[1])
		g[a-1] = append(g[a-1], b-1)
		g[b-1] = append(g[b-1], a-1)
	}
	var m int
	m = maxMatching(0, -1) / 2
	fmt.Fprintln(out, 2*m == n, "Second")
	// 