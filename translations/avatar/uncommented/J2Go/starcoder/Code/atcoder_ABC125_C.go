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
	input, _ := reader.ReadString('\n')
	input = strings.TrimSpace(input)
	N, _ := strconv.Atoi(input)
	A := make([]int, N)
	fmt.Println("Enter the elements of the array")
	for i := 0; i < N; i++ {
		fmt.Println("Enter the element at index", i)
		input, _ := reader.ReadString('\n')
		input = strings.TrimSpace(input)
		A[i], _ = strconv.Atoi(input)
	}
	L := make([]int, N)
	R := make([]int, N)
	L[0] = A[0]
	for i := 1; i < N; i++ {
		L[i] = gcd(L[i-1], A[i])
	}
	R[N-1] = A[N-1]
	for i := N - 2; i >= 0; i-- {
		R[i] = gcd(R[i+1], A[i])
	}
	answer := max(L[N-2], R[1])
	for i := 1; i < N-1; i++ {
		answer = max(answer, gcd(L[i-1], R[i+1]))
	}
	fmt.Println(answer)
}

func gcd(a, b int) int {
	tmp := 0
	if b > a {
		tmp = a
		a = b
		b = tmp
	}
	if b == 0 {
		return a
	}
	r := -1
	for {
		r = a % b
		a = b
		b = r
		if r == 0 {
			break
		}
	}
	return a
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

