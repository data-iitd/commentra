
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	var i, a, b, s int
	count := make([]int, 4)

	for i = 0; i < 4; i++ {
		count[i] = 0
	}

	for i = 0; i < 3; i++ {
		fmt.Fscanf(reader, "%d %d\n", &a, &b)
		count[a-1]++
		count[b-1]++
	}

	s = 1
	for i = 0; i < 4; i++ {
		s *= count[i]
	}

	if s == 4 {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}

