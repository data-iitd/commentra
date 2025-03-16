
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		N, _ := strconv.Atoi(scanner.Text())
		if N <= 0 {
			break
		}
		M := -1
		m := 1001
		addup := 0
		for i := 0; i < N; i++ {
			scanner.Scan()
			S, _ := strconv.Atoi(scanner.Text())
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
