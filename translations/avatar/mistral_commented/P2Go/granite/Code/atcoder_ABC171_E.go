
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	var n int
	fmt.Fscanf(reader, "%d\n", &n)

	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscanf(reader, "%d", &a[i])
	}

	total := 0
	for _, ai := range a {
		total ^= ai
	}

	for _, ai := range a {
		fmt.Printf("%d ", ai^total)
	}
	fmt.Println()
}
