package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var N int
	fmt.Scanf("%d", &N)
	A := make([]int, N)
	for i := 0; i < N; i++ {
		A[i] = (i + 1) * N
	}
	sort.Ints(A)
	cnt := 0
	for i := 0; i < N; i++ {
		d := A[i] % N
		if d%2!= i%2 {
			cnt++
		}
	}
	fmt.Printf("%d\n", cnt/2)
}

