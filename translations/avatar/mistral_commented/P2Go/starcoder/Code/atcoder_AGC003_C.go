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
	fmt.Print("Enter an integer: ")
	input, _ := reader.ReadString('\n')
	N, _ := strconv.Atoi(strings.TrimSpace(input))
	A := make([]int, N)
	for i := 0; i < N; i++ {
		A[i] = N*i + i
	}
	sort.Ints(A)
	cnt := 0
	for i := 0; i < N; i++ {
		d := A[i] % N % 2
		if d!= i % 2 {
			cnt++
		}
	}
	fmt.Println(cnt / 2)
}

