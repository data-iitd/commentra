
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	N, _ := strconv.Atoi(nextString(reader))
	X, _ := strconv.Atoi(nextString(reader))
	ans := 0
	min := 1000000000
	for i := 0; i < N; i++ {
		tmp, _ := strconv.Atoi(nextString(reader))
		X -= tmp
		ans++
		if tmp < min {
			min = tmp
		}
	}
	ans += X / min
	fmt.Println(ans)
}

func nextString(reader *bufio.Reader) string {
	s, _ := reader.ReadString('\n')
	for i := 0; i < len(s); i++ {
		if s[i] == '\n' {
			return s[:i]
		}
	}
	return s
}

