package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var (
		A []int
		n int
		i int
		j int
		t int
		sw int = 0
		mini int
	)

	n, _ = strconv.Atoi(strings.TrimSpace(os.Args[1]))
	A = make([]int, n)
	for i = 0; i < n; i++ {
		A[i], _ = strconv.Atoi(strings.TrimSpace(os.Args[i+2]))
	}

	for i = 0; i < n; i++ {
		mini = i
		for j = i; j < n; j++ {
			if A[j] < A[mini] {
				mini = j
			}
		}
		t = A[i]
		A[i] = A[mini]
		A[mini] = t
		if i!= mini {
			sw++
		}
	}

	for i = 0; i < n; i++ {
		if i!= 0 {
			fmt.Printf(" ")
		}
		fmt.Printf("%d", A[i])
	}
	fmt.Printf("\n")
	fmt.Printf("%d\n", sw)
}

