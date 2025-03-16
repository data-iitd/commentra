package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	in := bufio.NewScanner(os.Stdin)
	in.Split(bufio.ScanWords)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	in.Scan()
	n := parseInt(in.Text())
	list := make([]int, n)
	for i := 0; i < n; i++ {
		in.Scan()
		list[i] = parseInt(in.Text())
	}
	sort.Ints(list)
	c := 1
	for i := 0; i < n; i++ {
		if list[i] >= c {
			c++
		}
	}
	fmt.Fprintln(out, c)
}

func parseInt(s string) int {
	var res int
	fmt.Sscan(s, &res)
	return res
}

