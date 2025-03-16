
package main

import (
	"fmt"
	"math"
	"strconv"
	"strings"
)

// Function to check if given indices are valid
func valid(i, j, n, m int) bool {
	if i < n && i >= 0 && j >= 0 && j < m {
		return true
	}
	return false
}

// Function to calculate sum of first n natural numbers
func sumn(i, n int) int {
	return (n - i) * (i + n) / 2
}

// Function to calculate square root of a number using quadratic formula
func sqfun(a, b, c int) int {
	return (-b + int(math.Sqrt(float64(b*b-4*a*c)))) / 2 / a
}

// Function to read a single line as a tuple of integers
func value() (int, int) {
	var x, y int
	fmt.Scan(&x, &y)
	return x, y
}

// Function to read a single line as a list of integers
func values() []int {
	var x []int
	fmt.Scan(&x)
	return x
}

// Function to read a single integer
func inp() int {
	var x int
	fmt.Scan(&x)
	return x
}

// Function to read a single integer from the standard input as a string
func instr() string {
	var x string
	fmt.Scan(&x)
	return x
}

// Function to read a list of integers
func inlst() []int {
	var x []int
	fmt.Scan(&x)
	return x
}

// Function to read a list of integers from the standard input
func inlsts() []int {
	var x []int
	fmt.Scan(&x)
	return x
}

// Function to read a single integer from the standard input
func inp() int {
	var x int
	fmt.Scan(&x)
	return x
}

// Function to read a single integer from the standard input
func inps() int {
	var x int
	fmt.Scan(&x)
	return x
}

// Function to read a single string from the standard input
func instr() string {
	var x string
	fmt.Scan(&x)
	return x
}

// Function to convert a string to a list
func stlst() []string {
	var x []string
	fmt.Scan(&x)
	return x
}

// Main function to solve the problem
func solve() {
	var l []string
	for i := 0; i < 3; i++ {
		l = append(l, f(instr()))
	}
	t := permutations(l, len(l))
	l = []string{}
	for i := 0; i < len(t); i++ {
		l = append(l, strings.Join(t[i], ""))
	}
	for i := 0; i < inp(); i++ {
		if f(instr()) == l[i] {
			fmt.Println("ACC")
		} else {
			fmt.Println("WA")
		}
	}
}

// Function to generate all possible permutations of a list
func permutations(l []string, n int) [][]string {
	if n == 1 {
		return [][]string{l}
	}
	var t [][]string
	for i := 0; i < len(l); i++ {
		t = append(t, permutations(append(l[:i], l[i+1:]...), n-1)...)
	}
	return t
}

// Function to generate all possible permutations of a list
func permutations(l []int, n int) [][]int {
	if n == 1 {
		return [][]int{l}
	}
	var t [][]int
	for i := 0; i < len(l); i++ {
		t = append(t, permutations(append(l[:i], l[i+1:]...), n-1)...)
	}
	return t
}

// Function to generate all possible permutations of a list
func permutations(l []rune, n int) [][]rune {
	if n == 1 {
		return [][]rune{l}
	}
	var t [][]rune
	for i := 0; i < len(l); i++ {
		t = append(t, permutations(append(l[:i], l[i+1:]...), n-1)...)
	}
	return t
}

// Function to generate all possible permutations of a list
func permutations(l []byte, n int) [][]byte {
	if n == 1 {
		return [][]byte{l}
	}
	var t [][]byte
	for i := 0; i < len(l); i++ {
		t = append(t, permutations(append(l[:i], l[i+1:]...), n-1)...)
	}
	return t
}

// Function to generate all possible permutations of a list
func permutations(l []int8, n int) [][]int8 {
	if n == 1 {
		return [][]int8{l}
	}
	var t [][]int8
	for i := 0; i < len(l); i++ {
		t = append(t, permutations(append(l[:i], l[i+1:]...), n-1)...)
	}
	return t
}

// Function to generate all possible permutations of a list
func permutations(l []int16, n int) [][]int16 {
	if n == 1 {
		return [][]int16{l}
	}
	var t [][]int16
	for i := 0; i < len(l); i++ {
		t = append(t, permutations(append(l[:i], l[i+1:]...), n-1)...)
	}
	return t
}

// Function to generate all possible permutations of a list
func permutations(l []int32, n int) [][]int32 {
	if n == 1 {
		return [][]int32{l}
	}
	var t [][]int32
	for i := 0; i < len(l); i++ {
		t = append(t, permutations(append(l[:i], l[i+1:]...), n-1)...)
	}
	return t
}

// Function to generate all possible permutations of a list
func permutations(l []int64, n int) [][]int64 {
	if n == 1 {
		return [][]int64{l}
	}
	var t [][]int64
	for i := 0; i < len(l); i++ {
		t = append(t, permutations(append(l[:i], l[i+1:]...), n-1)...)
	}
	return t
}

// Function to generate all possible permutations of a list
func permutations(l []uint, n int) [][]uint {
	if n == 1 {
		return [][]uint{l}
	}
	var t [][]uint
	for i := 0; i < len(l); i++ {
		t = append(t, permutations(append(l[:i], l[i+1:]...), n-1)...)
	}
	return t
}

// Function to generate all possible permutations of a list
func permutations(l []uint8, n int) [][]uint8 {
	if n == 1 {
		return [][]uint8{l}
	}
	var t [][]uint8
	for i := 0; i < len(l); i++ {
		t = append(t, permutations(append(l[:i], l[i+1:]...), n-1)...)
	}
	return t
}

// Function to generate all possible permutations of a list
func permutations(l []uint16, n int) [][]uint16 {
	if n == 1 {
		return [][]uint16{l}
	}
	var t [][]uint16
	for i := 0; i < len(l); i++ {
		t = append(t, permutations(append(l[:i], l[i+1:]...), n-1)...)
	}
	return t
}

// Function to generate all possible permutations of a list
func permutations(l []uint32, n int) [][]uint32 {
	if n == 1 {
		return [][]uint32{l}
	}
	var t [][]uint32
	for i := 0; i < len(l); i++ {
		t = append(t, permutations(append(l[:i], l[i+1:]...), n-1)...)
	}
	return t
}

// Function to generate all possible permutations of a list
func permutations(l []uint64, n int) [][]uint64 {
	if n == 1 {
		return [][]uint64{l}
	}
	var t [][]uint64
	for i := 0; i < len(l); i++ {
		t = append(t, permutations(append(l[:i], l[i+1:]...), n-1)...)
	}
	return t
}

// Function to generate all possible permutations of a list
func permutations(l []float32, n int) [][]float32 {
	if n == 1 {
		return [][]float32{l}
	}
	var t [][]float32
	for i := 0; i < len(l); i++ {
		t = append(t, permutations(append(l[:i], l[i+1:]...), n-1)...)
	}
	return t
}

// Function to generate all possible permutations of a list
func permutations(l []float64, n int) [][]float64 {
	if n == 1 {
		return [][]float64{l}
	}
	var t [][]float64
	for i := 0; i < len(l); i++ {
		t = append(t, permutations(append(l[:i], l[i+1:]...), n-1)...)
	}
	return t
}

// Function to generate all possible permutations of a list
func permutations(l []complex64, n int) [][]complex64 {
	if n == 1 {
		return [][]complex64{l}
	}
	var t [][]complex64
	for i := 0; i < len(l); i++ {
		t = append(t, permutations(append(l[:i], l[i+1:]...), n-1)...)
	}
	return t
}

// Function to generate all possible permutations of a list
func permutations(l []complex128, n int) [][]complex128 {
	if n == 1 {
		return [][]complex128{l}
	}
	var t [][]complex128
	for i := 0; i < len(l); i++ {
		t = append(t, permutations(append(l[:i], l[i+1:]...), n-1)...)
	}
	return t
}

// Function to generate all possible permutations of a list
func permutations(l []string, n int) [][]string {
	if n == 1 {
		return [][]string{l}
	}
	var t [][]string
	for i := 0; i < len(l); i++ {
		t = append(t, permutations(append(l[:i], l[i+1:]...), n-1)...)
	}
	return t
}

// Function to generate all possible permutations of a list
func permutations(l []bool, n int) [][]bool {
	if n == 1 {
		return [][]bool{l}
	}
	var t [][]bool
	for i := 0; i < len(l); i++ {
		t = append(t, permutations(append(l[:i], l[i+1:]...), n-1)...)
	}
	return t
}

// Function to generate all possible permutations of a list
func permutations(l []rune, n int) [][]rune {
	if n == 1 {
		return [][]rune{l}
	}
	var t [][]rune
	for i := 0; i < len(l); i++ {
		t = append(t, permutations(append(l[:i], l[i+1:]...), n-1)...)
	}
	return t
}

// Function to generate all possible permutations of a list
func permutations(l []byte, n int) [][]byte {
	if n == 1 {
		return [][]byte{l}
	}
	var t [][]byte
	for i := 0; i < len(l); i++ {
		t = append(t, permutations(append(l[:i], l[i+1:]...), n-1)...)
	}
	return t
}

// Function to generate all possible permutations of a list
func permutations(l []int8, n int) [][]int8 {
	if n == 1 {
		return [][]int8{l}
	}
	var t [][]int8
	for i := 0; i < len(l); i++ {
		t = append(t, permutations(append(l[:i], l[i+1:]...), n-1)...)
	}
	return t
}

// Function to generate all possible permutations of a list
func permutations(l []int16, n int) [][]int16 {
	if n == 1 {
		return [][]int16{l}
	}
	var t [][]int16
	for i := 0; i < len(l); i++ {
		t = append(t, permutations(append(l[:i], l[i+1:]...), n-1)...)
	}
	return t
}

// Function to generate all possible permutations of a list
func permutations(l []int32, n int) [][]int32 {
	if n == 1 {
		return [][]int32{l}
	}
	var t [][]int32
	for i := 0; i < len(l); i++ {
		t = append(t, permutations(append(l[:i], l[i+1:]...), n-1)...)
	}
	return t
}

// Function to generate all possible permutations of a list
func permutations(l []int64, n int) [][]int64 {
	if n == 1 {
		return [][]int64{l}
	}
	var t [][]int64
	for i := 0; i < len(l); i++ {
		t = append(t, permutations(append(l[:i], l[i+1:]...), n-1)...)
	}
	return t
}

// Function to generate all possible permutations of a list
func permutations(l []uint, n int) [][]uint {
	if n == 1 {
		return [][]uint{l}
	}
	var t [][]uint
	for i := 0; i < len(l); i++ {
		t = append(t, permutations(append(l[:i], l[i+1:]...), n-1)...)
	}
	return t
}

// Function to generate all possible permutations of a list
func permutations(l []uint8, n int) [][]uint8 {
	if n == 1 {
		return [][]uint8{l}
	}
	var t [][]uint8
	for i := 0; i < len(l); i++ {
		t = append(t, permutations(append(l[:i], l[i+1:]...), n-1)...)
	}
	return t
}

// Function to generate all possible permutations of a list
func permutations(l []uint16, n int) [][]uint16 {
	if n == 1 {
		return [][]uint16{l}
	}
	var t [][]uint16
	for i := 0; i < len(l); i++ {
		t = append(t, permutations(append(l[:i], l[i+1:]...), n-1)...)
	}
	return t
}

// Function to generate all possible permutations of a list
func permutations(l []uint32, n int) [][]uint32 {
	if n == 1 {
		return [][]uint32{l}
	}
	var t [][]uint32
	for i := 0; i < len(l); i++ {
		t = append(t, permutations(append(l