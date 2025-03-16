
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	const initialBufSize = 4096
	const maxBufSize = 1000000
	scanner.Buffer(make([]byte, initialBufSize), maxBufSize)
	scanner.Split(bufio.ScanWords)
	var N int
	scanner.Scan()
	N, _ = fmt.Sscanf(scanner.Text(), "%d")
	mem := make([]int, N+1)
	for i := 1; i <= N; i++ {
		scanner.Scan()
		P, _ := fmt.Sscanf(scanner.Text(), "%d")
		mem[P] = i
	}

	maxcnt := 1
	cnt := 1
	for i := 1; i < N; i++ {
		if mem[i] < mem[i+1] {
			cnt++
		} else {
			if maxcnt < cnt {
				maxcnt = cnt
			}
			cnt = 1
		}
		if i == N-1 {
			if maxcnt < cnt {
				maxcnt = cnt
			}
		}
	}
	//cnt = 1
	//for i := N; i > 1; i-- {
	//	if mem[i] > mem[i-1] {
	//		cnt++
	//	}
	//}

	fmt.Println(N - maxcnt)
}

