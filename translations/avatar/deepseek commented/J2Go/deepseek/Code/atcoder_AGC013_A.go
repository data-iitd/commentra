package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	N, _ := fmt.Sscanf(scanner.Text(), "%d", &N)
	A := make([]int, N)
	for i := 0; i < N; i++ {
		scanner.Scan()
		fmt.Sscanf(scanner.Text(), "%d", &A[i])
	}
	count := 0
	for i := 0; i < N; i++ {
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

