package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	var N int
	var A []int
	var tomatu []int
	var mikakosi []int
	var yukinnko int
	var inorinn int
	var emirinn int
	var kugyu int
	var isihasu int
	var matukisu int
	var satorina int
	var zaasan int
	var yukati int
	var hayaminn int
	var err error
	var scanner *bufio.Scanner
	scanner = bufio.NewScanner(os.Stdin)
	if scanner.Scan() {
		N, err = strconv.Atoi(scanner.Text())
		if err!= nil {
			fmt.Fprintln(os.Stderr, err)
			os.Exit(1)
		}
	}
	for inorinn = 0; inorinn < N; inorinn++ {
		if scanner.Scan() {
			isihasu, err = strconv.Atoi(scanner.Text())
			if err!= nil {
				fmt.Fprintln(os.Stderr, err)
				os.Exit(1)
			}
			A = append(A, isihasu)
		}
	}
	sort.Slice(A, func(i, j int) bool { return A[i] < A[j] })
	yukinnko = 1
	for inorinn = 1; inorinn < N; inorinn++ {
		if A[inorinn]!= A[yukinnko-1] {
			tomatu = append(tomatu, A[inorinn])
			yukinnko++
		}
	}
	for inorinn = 0; inorinn < N; inorinn++ {
		kugyu = sort.Search(yukinnko, func(i int) bool { return tomatu[i] >= A[inorinn] })
		mikakosi[kugyu] =!mikakosi[kugyu]
	}
	for inorinn = 0; inorinn < yukinnko; inorinn++ {
		if mikakosi[inorinn] {
			emirinn++
		}
	}
	fmt.Println(emirinn)
}

