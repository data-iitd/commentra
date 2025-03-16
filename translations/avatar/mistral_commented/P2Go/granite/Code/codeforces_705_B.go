
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	n, _ := fmt.Fscanf(reader, "%d\n", &n)

	w := make([]int, n)

	for i := 0; i < n; i++ {
		fmt.Fscanf(reader, "%d\n", &w[i])
	}

	c := 2

	for _, number := range w {
		if number == 1 {
			fmt.Println(c)
		} else if number%2 == 0 {
			c = 3 - c
			fmt.Println(c)
		} else {
			fmt.Println(c)
		}
	}
}
