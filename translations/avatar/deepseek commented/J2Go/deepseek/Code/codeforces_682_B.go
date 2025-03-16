package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	scanner.Scan()
	n, _ := fmt.Sscan(scanner.Text(), &n)
	list := make([]int, n)

	for i := 0; i < n; i++ {
		scanner.Scan()
		fmt.Sscan(scanner.Text(), &list[i])
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

