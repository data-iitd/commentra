
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
		N, err := strconv.Atoi(reader.ReadLine())
		if err!= nil {
			break
		}
		M := -1
		m := 1001
		addup := 0
		for i := 0; i < N; i++ {
			S, err := strconv.Atoi(reader.ReadLine())
			if err!= nil {
				break
			}
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
