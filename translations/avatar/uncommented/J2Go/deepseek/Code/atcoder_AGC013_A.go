package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	N, _ := fmt.Sscan(scanner.Text(), &N)
	A := make([]int, N)
	for i := 0; i < N; i++ {
		scanner.Scan()
		fmt.Sscan(scanner.Text(), &A[i])
	}
	count := 0
	for i := 0; i < N; i++ {
		if i == N-1 {
			count++
		} else if A[i] == A[i+1] {
		} else if A[i] < A[i+1] {
			for i < N-1 && A[i] <= A[i+1] {
				i++
			}
			count++
		} else {
			for i < N-1 && A[i] >= A[i+1] {
				i++
			}
			count++
		}
	}
	fmt.Println(count)
}

