
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(read(reader))
	ans := make([]int, n)
	for i := 0; i < n-1; i++ {
		a, _ := strconv.Atoi(read(reader))
		ans[a-1]++
	}
	for i := 0; i < n; i++ {
		fmt.Println(ans[i])
	}
}

func read(reader *bufio.Reader) string {
	s, _ := reader.ReadString('\n')
	s = s[:len(s)-1]
	return s
}

