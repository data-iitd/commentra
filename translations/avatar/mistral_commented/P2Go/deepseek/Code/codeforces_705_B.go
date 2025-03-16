package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var n int
	fmt.Fscan(reader, &n)

	w := make([]int, n)
	for i := 0; i < n; i++ {
		var temp string
		fmt.Fscan(reader, &temp)
		num, _ := strconv.Atoi(temp)
		w[i] = num
	}

	c := 2
	for _, number := range w {
		if number == 1 {
			fmt.Fprintln(writer, c)
		} else if number%2 == 0 {
			c = 3 - c
			fmt.Fprintln(writer, c)
		} else {
			fmt.Fprintln(writer, c)
		}
	}
}

