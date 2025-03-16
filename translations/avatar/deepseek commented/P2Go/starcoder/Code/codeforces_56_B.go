
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter the number of elements in the list")
	N, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	fmt.Println("Enter the elements of the list")
	A := make([]int, N)
	for i := 0; i < N; i++ {
		A[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	}
	mn, mx := N+1, -1
	for i := 0; i < N; i++ {
		if i+1!= A[i] {
			mn = min(mn, i)
			mx = max(mx, i)
		}
	}
	if mx == -1 {
		fmt.Println("0 0")
	} else {
		for i := mn; i <= mx; i++ {
			A[i], A[mx] = A[mx], A[i]
			mx--
		}
		if sorted(A) == A {
			fmt.Println(mn+1, mx+1)
		} else {
			fmt.Println("0 0")
		}
	}
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func sorted(A []int) bool {
	for i := 0; i < len(A)-1; i++ {
		if A[i] > A[i+1] {
			return false
		}
	}
	return true
}

