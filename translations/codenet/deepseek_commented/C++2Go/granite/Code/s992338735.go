
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	for {
		N, _ := strconv.Atoi(read(reader))
		if N <= 0 {
			break
		}
		M, m, addup, i := -1, 1001, 0, 0
		for ; i < N; i++ {
			S, _ := strconv.Atoi(read(reader))
			addup += S
			if S > M {
				M = S
			}
			if S < m {
				m = S
			}
		}
		fmt.Println((addup - M - m) / (N - 2))
	}
}

func read(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err!= nil {
		panic(err)
	}
	return string(str)
}

