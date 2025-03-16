package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

const (
	MAX_N = 2000001
	MAX_Ai = 10001
	STR_SIZE = 10000010
)

func main() {
	var (
		i int
		n int
	)

	reader := bufio.NewReader(os.Stdin)
	str, _ := reader.ReadString('\n')
	str = strings.TrimSpace(str)
	n, _ = strconv.Atoi(str)

	for i = 1; i <= n; i++ {
		str, _ = reader.ReadString('\n')
		str = strings.TrimSpace(str)
		A[i], _ = strconv.Atoi(str)
	}

	countingSort(A, B, MAX_Ai, n)

	p = str
	n--
	for i = 1; i <= n; i++ {
		fmt.Printf("%d ", B[i])
	}
	fmt.Printf("%d\n", B[i])
}

func countingSort(A []int, B []int, k int, len int) {
	var (
		C [MAX_Ai]int
		i int
		j int
	)

	for j = 1; j <= len; j++ {
		C[A[j]]++
	}
	for i = 1; i <= k; i++ {
		C[i] += C[i-1]
	}
	for j = len; j > 0; j-- {
		B[C[A[j]]] = A[j]
		C[A[j]]--
	}
}

