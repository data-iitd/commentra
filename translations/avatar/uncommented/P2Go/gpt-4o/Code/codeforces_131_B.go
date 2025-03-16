package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	n := readInt(reader)
	w := make(map[int]int)

	// Read the integers and count occurrences
	for i := 0; i < n; i++ {
		num := readInt(reader)
		w[num]++
	}

	c := 0
	for i := range w {
		if i == 0 {
			c += w[i] * (w[i] - 1)
		} else {
			if count, exists := w[-i]; exists {
				c += w[i] * count
			}
		}
	}
	fmt.Println(c / 2)
}

func readInt(reader *bufio.Reader) int {
	var x int
	fmt.Fscan(reader, &x)
	return x
}

// <END-OF-CODE>
