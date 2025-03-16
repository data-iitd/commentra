package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var n int
	fmt.Fscan(reader, &n)

	list := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(reader, &list[i])
	}
	sort.Ints(list)

	c := 1
	for i := 0; i < n; i++ {
		if list[i] >= c {
			c++
		}
	}
	fmt.Fprintln(writer, c)
}

