package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var N, D, X int
	var num_of_chocolate int
	var counter int
	var days int
	var A [101]int
	fmt.Scanf("%d %d %d", &N, &D, &X)
	for i := 0; i < N; i++ {
		fmt.Scanf("%d", &A[i])
	}
	num_of_chocolate = 0
	for i := 0; i < N; i++ {
		days = 0
		counter = 0
		for j := 0; ; j++ {
			days = j * A[i] + 1
			if days <= D {
				counter++
			} else {
				break
			}
		}
		num_of_chocolate = num_of_chocolate + counter
	}
	num_of_chocolate = num_of_chocolate + X
	fmt.Printf("%d\n", num_of_chocolate)
}

