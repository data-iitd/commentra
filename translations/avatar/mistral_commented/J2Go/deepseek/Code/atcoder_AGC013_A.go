package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscan(reader, &N)
	A := make([]int, N)

	for i := 0; i < N; i++ {
		fmt.Fscan(reader, &A[i])
	}

	count := 0

	for i := 0; i < N-1; i++ {
		if i == N-1 {
			count++
		} else if A[i] == A[i+1] {
		} else if A[i] < A[i+1] {
			for A[i] <= A[i+1] {
				i++
				if i == N-1 {
					break
				}
			}
			count++
		} else {
			for A[i] >= A[i+1] {
				i++
				if i == N-1 {
					break
				}
			}
			count++
		}
	}

	fmt.Println(count)
}

