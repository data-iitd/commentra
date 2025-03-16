package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var n int
	fmt.Fscan(reader, &n)

	w := make(map[int]int)
	for i := 0; i < n; i++ {
		var num int
		fmt.Fscan(reader, &num)
		w[num]++
	}

	c := 0
	for i, count := range w {
		if i == 0 {
			c += count * (count - 1)
		} else if count2, found := w[-i]; found {
			c += count * count2
		}
	}

	fmt.Fprintln(writer, c/2)
}

