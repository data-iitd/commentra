// Import necessary packages and functions
package main

import (
	"fmt"
	"math"
	"sort"
	"strconv"
	"strings"
)

// Set input parameters and initialize variables
func input() string {
	return strings.TrimSpace(readLine())
}

func readLine() string {
	var line string
	if _, err := fmt.Scan(&line); err != nil {
		panic(err)
	}
	return line
}

func INT() int {
	return int(inputInt64())
}

func inputInt64() int64 {
	i, err := strconv.ParseInt(input(), 0, 64)
	if err != nil {
		panic(err.Error())
	}
	return i
}

func LIST() []int {
	return inputInts()
}

func inputInts() []int {
	var ints []int
	for _, s := range strings.Split(input(), " ") {
		i, err := strconv.Atoi(s)
		if err != nil {
			panic(err.Error())
		}
		ints = append(ints, i)
	}
	return ints
}

func main() {
	N := INT()
	A := LIST()
	A = groupBy(A)
	N = len(A)
	i := 1
	ans := 0
	for i < N-1 {
		if A[i-1] < A[i] && A[i] > A[i+1] || A[i-1] > A[i] && A[i] < A[i+1] {
			ans++
			i++
		} else {
			i++
		}
	}
	i++
	fmt.Println(ans + 1)
}

func groupBy(A []int) []int {
	var keys []int
	for i := 0; i < len(A); i++ {
		if i == 0 || A[i] != A[i-1] {
			keys = append(keys, A[i])
		}
	}
	return keys
}

