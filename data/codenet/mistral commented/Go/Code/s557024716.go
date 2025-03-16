/*
URL:
https://atcoder.jp/contests/m-solutions2020/tasks/m_solutions2020_b
*/

package main

import (
	"bufio"
	"errors"
	"fmt"
	"io"
	"math"
	"os"
	"strconv"
)

/********** FAU standard libraries **********/

//fmt.Sprintf("%b\n", 255) 	// binary expression

/********** I/O usage **********/

//str := ReadString()
//i := ReadInt()
//X := ReadIntSlice(n)
//S := ReadRuneSlice()
//a := ReadFloat64()
//A := ReadFloat64Slice(n)

//str := ZeroPaddingRuneSlice(num, 32)
//str := PrintIntsLine(X...)

/*******************************************************************/

const (
	// General purpose
	MOD = 1000000000 + 7
	// MOD          = 998244353
	ALPHABET_NUM = 26
	INF_INT64    = math.MaxInt64
	INF_BIT60    = 1 << 60
	INF_INT32    = math.MaxInt32
	INF_BIT30    = 1 << 30
	NIL          = -1

	// for dijkstra, prim, and so on
	WHITE = 0
	GRAY  = 1
	BLACK = 2
)

func init() {
	// bufio.ScanWords <---> bufio.ScanLines
	ReadString = newReadString(os.Stdin, bufio.ScanWords)
	stdout = bufio.NewWriter(os.Stdout)
}

var (
	a, b, c int
	k       int
)

func main() {
	// Read input values
	a, b, c = ReadInt3()
	k = ReadInt()

	// Generate all possible patterns of length k from the given array [0, 1, 2, 3]
	patterns := DuplicatePatterns([]int{0, 1, 2, 3}, k)

	// Check each generated pattern
	for _, P := range patterns {
		// Apply bitwise operation to RGB values of the given input
		r, g, b := a, b, c
		for i := 0; i < len(P); i++ {
			if P[i] == 0 {
				continue
			} else if P[i] == 1 {
				r *= 2
			} else if P[i] == 2 {
				g *= 2
			} else if P[i] == 3 {
				b *= 2
			}
		}

		// Check if the result satisfies the condition g > r and b > g
		if g > r && b > g {
			fmt.Println("Yes")
			return
		}
	}

	// If all patterns are checked and no satisfying pattern is found, print "No"
	fmt.Println("No")
}

// DuplicatePatterns returns all patterns of n^k of elems([]int).
func DuplicatePatterns(elems []int, k int) [][]int {
	return dupliRec([]int{}, elems, k)
}

// DFS function for DuplicatePatterns.
func dupliRec(pattern, elems []int, k int) [][]int {
	if len(pattern) == k {
		// Return the generated pattern as a slice
		return [][]int{pattern}
	}

	res := [][]int{}
	for _, e := range elems {
		// Create a new pattern by appending the current element to the current pattern
		newPattern := make([]int, len(pattern)+1)
		copy(newPattern, pattern)
		newPattern[len(pattern)] = e

		// Recursively call the function with the new pattern and the remaining elements
		subPatterns := dupliRec(newPattern, elems, k)

		// Append the sub-patterns to the result
		res = append(res, subPatterns...)
	}

	return res
}
