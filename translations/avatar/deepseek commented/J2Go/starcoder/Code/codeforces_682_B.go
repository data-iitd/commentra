package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	var n int
	fmt.Fscan(in, &n)
	list := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &list[i])
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

