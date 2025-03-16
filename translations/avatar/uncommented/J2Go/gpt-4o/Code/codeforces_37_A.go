package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	input := bufio.NewReader(os.Stdin)
	var n int
	fmt.Fscan(input, &n)

	counts := make(map[int]int)
	for i := 0; i < n; i++ {
		var val int
		fmt.Fscan(input, &val)
		counts[val]++
	}

	max := 0
	for _, value := range counts {
		if value > max {
			max = value
		}
	}

	fmt.Printf("%d%d\n", max, len(counts))
}

// <END-OF-CODE>
