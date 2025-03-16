
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	count := make([]int, 4)
	for i := 0; i < 3; i++ {
		a, _ := strconv.Atoi(read(reader))
		b, _ := strconv.Atoi(read(reader))
		count[a-1]++
		count[b-1]++
	}
	s := 1
	for i := 0; i < 4; i++ {
		s *= count[i]
	}
	if s == 4 {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}

func read(reader *bufio.Reader) string {
	str, _, _ := reader.ReadLine()
	return string(str)
}

