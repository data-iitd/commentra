
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
	fmt.Println("Enter the number of elements in the array")
	N, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	A := make([]int, N)
	fmt.Println("Enter the elements of the array")
	for i := 0; i < N; i++ {
		A[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	}
	if possible(N, A) {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}

func possible(N int, A []int) bool {
	sum := 0
	for i := 0; i < N; i++ {
		sum += A[i]
	}
	NS := (N * (N + 1)) / 2
	if sum%NS!= 0 {
		return false
	}
	K := sum / NS
	for i := 0; i < N; i++ {
		j := i - 1
		if j < 0 {
			j = N - 1
		}
		d := K - (A[i] - A[j])
		if d < 0 || d%N!= 0 {
			return false
		}
	}
	return true
}

