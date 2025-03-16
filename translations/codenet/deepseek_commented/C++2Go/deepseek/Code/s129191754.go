package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var n int
	fmt.Fscan(reader, &n)

	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(reader, &a[i])
	}

	sort.Ints(a)

	for i := 0; i < n-1; i++ {
		if a[i] == a[i+1] {
			fmt.Fprintln(writer, "NO")
			return
		}
	}

	fmt.Fprintln(writer, "YES")
}

