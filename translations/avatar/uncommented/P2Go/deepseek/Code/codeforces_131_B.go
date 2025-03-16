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
	input, _ := reader.ReadString('\n')
	for _, num := range strings.Fields(input) {
		numInt, _ := strconv.Atoi(num)
		w[numInt]++
	}

	c := 0
	for i := range w {
		if i == 0 {
			c += w[i] * (w[i] - 1)
		} else {
			if _, exists := w[-i]; exists {
				c += w[i] * w[-i]
			}
		}
	}
	fmt.Fprintln(writer, c/2)
}

