// Package declaration and importing necessary packages
package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"sort"
	"strconv"
)

// Main function declaration and initialization of constants
func main() {
	const INF int = int(math.Pow10(11)) // Large constant value for initializing arrays

	// Reading input values from standard input
	A := nextInt()
	B := nextInt()
	Q := nextInt()

	// Initializing arrays s and t with size A+2 and B+2 respectively
	// The first and last elements are initialized with -INF and INF respectively
	s := make([]int, A+2)
	s[0], s[A+1] = -INF, INF

	// Reading A elements of array s from standard input
	for i := 1; i <= A; i++ {
		s[i] = nextInt()
	}

	// Initializing array t with size B+2
	// The first and last elements are initialized with -INF and INF respectively
	t := make([]int, B+2)
	t[0], t[B+1] = -INF, INF

	// Reading B elements of array t from standard input
	for i := 1; i <= B; i++ {
		t[i] = nextInt()
	}

	// Processing each query
	for i := 0; i < Q; i++ {
		// Reading query value x from standard input
		x := nextInt()

		// Finding the indices b and d of array s and t respectively
		// where s[b] and t[d] are the smallest elements greater than x
		b, d := sort.SearchInts(s, x), sort.SearchInts(t, x)

		// Computing the minimum distance between x and any pair of elements S and T
		// from arrays s and t respectively
		res := INF
		for _, S := range []int{s[b-1], s[b]} {
			for _, T := range []int{t[d-1], t[d]} {
				// Computing the absolute difference between S and x, and T and S
				d1, d2 := abs(S-x), abs(T-S)

				// Updating the minimum distance if the current pair has a smaller distance
				res = min(res, min(d1, d2))
			}
		}

		// Printing the minimum distance for the current query
		fmt.Println(res)
	}
}

// Input reading helper functions
var sc = bufio.NewScanner(os.Stdin)

func init() {
	sc.Buffer([]byte{}, math.MaxInt64)
	sc.Split(bufio.ScanWords)
}

func nextInt() int {
	sc.Scan()
	i, err := strconv.Atoi(sc.Text())
	if err != nil {
		panic(err)
	}

	return i
}

func nextFloat() float64 {
	sc.Scan()
	f64, err := strconv.ParseFloat(sc.Text(), 64)
	if err != nil {
		panic(err)
	}

	return f64
}

func nextString() string {
	sc.Scan()
	if err := sc.Err(); err != nil {
		panic(err)
	}

	return sc.Text()
}

// Helper functions for array manipulation and arithmetic operations
func abs(x int) int {
	return int(math.Abs(float64(x)))
}

func min(x, y int) int {
	return int(math.Min(float64(x), float64(y)))
}

func max(x, y int) int {
	return int(math.Max(float64(x), float64(y)))
}
