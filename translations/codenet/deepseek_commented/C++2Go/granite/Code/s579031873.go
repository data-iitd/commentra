
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	N, _ := strconv.Atoi(read(reader))
	X, _ := strconv.Atoi(read(reader))
	ans := 0
	min := 1000000000
	for i := 0; i < N; i++ {
		tmp, _ := strconv.Atoi(read(reader))
		X -= tmp
		ans++
		if tmp < min {
			min = tmp
		}
	}
	ans += X / min
	fmt.Println(ans)
}

func read(reader *bufio.Reader) string {
	s, _ := reader.ReadString('\n')
	s = s[:len(s)-1]
	return s
}

