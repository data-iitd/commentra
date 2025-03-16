
package main

import (
	"fmt"
	"os"
)

// Function to read input from standard input
func input() string {
	var s string
	fmt.Scan(&s)
	return s
}

// Function to read input from standard input
func inputInt() int {
	var n int
	fmt.Scan(&n)
	return n
}

// Function to read input from standard input
func inputIntArray() []int {
	var n int
	fmt.Scan(&n)
	a := make([]int, n)
	for i := range a {
		fmt.Scan(&a[i])
	}
	return a
}

// Function to read input from standard input
func inputIntMatrix() [][]int {
	var n, m int
	fmt.Scan(&n, &m)
	a := make([][]int, n)
	for i := range a {
		a[i] = make([]int, m)
		for j := range a[i] {
			fmt.Scan(&a[i][j])
		}
	}
	return a
}

// Function to read input from standard input
func inputString() string {
	var s string
	fmt.Scan(&s)
	return s
}

// Function to read input from standard input
func inputStringArray() []string {
	var n int
	fmt.Scan(&n)
	a := make([]string, n)
	for i := range a {
		fmt.Scan(&a[i])
	}
	return a
}

// Function to read input from standard input
func inputStringMatrix() [][]string {
	var n, m int
	fmt.Scan(&n, &m)
	a := make([][]string, n)
	for i := range a {
		a[i] = make([]string, m)
		for j := range a[i] {
			fmt.Scan(&a[i][j])
		}
	}
	return a
}

// Function to read input from standard input
func inputIntMatrixFromReader(reader *bufio.Reader) [][]int {
	var n, m int
	fmt.Fscan(reader, &n, &m)
	a := make([][]int, n)
	for i := range a {
		a[i] = make([]int, m)
		for j := range a[i] {
			fmt.Fscan(reader, &a[i][j])
		}
	}
	return a
}

// Function to read input from standard input
func inputStringMatrixFromReader(reader *bufio.Reader) [][]string {
	var n, m int
	fmt.Fscan(reader, &n, &m)
	a := make([][]string, n)
	for i := range a {
		a[i] = make([]string, m)
		for j := range a[i] {
			fmt.Fscan(reader, &a[i][j])
		}
	}
	return a
}

// Function to read input from standard input
func inputIntArrayFromReader(reader *bufio.Reader) []int {
	var n int
	fmt.Fscan(reader, &n)
	a := make([]int, n)
	for i := range a {
		fmt.Fscan(reader, &a[i])
	}
	return a
}

// Function to read input from standard input
func inputStringArrayFromReader(reader *bufio.Reader) []string {
	var n int
	fmt.Fscan(reader, &n)
	a := make([]string, n)
	for i := range a {
		fmt.Fscan(reader, &a[i])
	}
	return a
}

// Function to read input from standard input
func inputIntMatrixFromFile(filename string) [][]int {
	file, err := os.Open(filename)
	if err != nil {
		log.Fatal(err)
	}
	defer file.Close()
	reader := bufio.NewReader(file)
	return inputIntMatrixFromReader(reader)
}

// Function to read input from standard input
func inputStringMatrixFromFile(filename string) [][]string {
	file, err := os.Open(filename)
	if err != nil {
		log.Fatal(err)
	}
	defer file.Close()
	reader := bufio.NewReader(file)
	return inputStringMatrixFromReader(reader)
}

// Function to read input from standard input
func inputIntArrayFromFile(filename string) []int {
	file, err := os.Open(filename)
	if err != nil {
		log.Fatal(err)
	}
	defer file.Close()
	reader := bufio.NewReader(file)
	return inputIntArrayFromReader(reader)
}

// Function to read input from standard input
func inputStringArrayFromFile(filename string) []string {
	file, err := os.Open(filename)
	if err != nil {
		log.Fatal(err)
	}
	defer file.Close()
	reader := bufio.NewReader(file)
	return inputStringArrayFromReader(reader)
}

// Function to read input from standard input
func inputIntMatrixFromStdin() [][]int {
	reader := bufio.NewReader(os.Stdin)
	return inputIntMatrixFromReader(reader)
}

// Function to read input from standard input
func inputStringMatrixFromStdin() [][]string {
	reader := bufio.NewReader(os.Stdin)
	return inputStringMatrixFromReader(reader)
}

// Function to read input from standard input
func inputIntArrayFromStdin() []int {
	reader := bufio.NewReader(os.Stdin)
	return inputIntArrayFromReader(reader)
}

// Function to read input from standard input
func inputStringArrayFromStdin() []string {
	reader := bufio.NewReader(os.Stdin)
	return inputStringArrayFromReader(reader)
}

// Function to read input from standard input
func inputIntMatrixFromStdinWithSize() (int, int, [][]int) {
	var n, m int
	fmt.Scan(&n, &m)
	a := make([][]int, n)
	for i := range a {
		a[i] = make([]int, m)
		for j := range a[i] {
			fmt.Scan(&a[i][j])
		}
	}
	return n, m, a
}

// Function to read input from standard input
func inputStringMatrixFromStdinWithSize() (int, int, [][]string) {
	var n, m int
	fmt.Scan(&n, &m)
	a := make([][]string, n)
	for i := range a {
		a[i] = make([]string, m)
		for j := range a[i] {
			fmt.Scan(&a[i][j])
		}
	}
	return n, m, a
}

// Function to read input from standard input
func inputIntArrayFromStdinWithSize() (int, []int) {
	var n int
	fmt.Scan(&n)
	a := make([]int, n)
	for i := range a {
		fmt.Scan(&a[i])
	}
	return n, a
}

// Function to read input from standard input
func inputStringArrayFromStdinWithSize() (int, []string) {
	var n int
	fmt.Scan(&n)
	a := make([]string, n)
	for i := range a {
		fmt.Scan(&a[i])
	}
	return n, a
}

// Function to read input from standard input
func inputIntMatrixFromStdinWithSize2() (int, int, [][]int) {
	var n, m int
	fmt.Scan(&n, &m)
	a := make([][]int, n)
	for i := range a {
		a[i] = make([]int, m)
		for j := range a[i] {
			fmt.Scan(&a[i][j])
		}
	}
	return n, m, a
}

// Function to read input from standard input
func inputStringMatrixFromStdinWithSize2() (int, int, [][]string) {
	var n, m int
	fmt.Scan(&n, &m)
	a := make([][]string, n)
	for i := range a {
		a[i] = make([]string, m)
		for j := range a[i] {
			fmt.Scan(&a[i][j])
		}
	}
	return n, m, a
}

// Function to read input from standard input
func inputIntArrayFromStdinWithSize2() (int, []int) {
	var n int
	fmt.Scan(&n)
	a := make([]int, n)
	for i := range a {
		fmt.Scan(&a[i])
	}
	return n, a
}

// Function to read input from standard input
func inputStringArrayFromStdinWithSize2() (int, []string) {
	var n int
	fmt.Scan(&n)
	a := make([]string, n)
	for i := range a {
		fmt.Scan(&a[i])
	}
	return n, a
}

// Function to read input from standard input
func inputIntMatrixFromStdinWithSize3() (int, int, [][]int) {
	var n, m int
	fmt.Scan(&n, &m)
	a := make([][]int, n)
	for i := range a {
		a[i] = make([]int, m)
		for j := range a[i] {
			fmt.Scan(&a[i][j])
		}
	}
	return n, m, a
}

// Function to read input from standard input
func inputStringMatrixFromStdinWithSize3() (int, int, [][]string) {
	var n, m int
	fmt.Scan(&n, &m)
	a := make([][]string, n)
	for i := range a {
		a[i] = make([]string, m)
		for j := range a[i] {
			fmt.Scan(&a[i][j])
		}
	}
	return n, m, a
}

// Function to read input from standard input
func inputIntArrayFromStdinWithSize3() (int, []int) {
	var n int
	fmt.Scan(&n)
	a := make([]int, n)
	for i := range a {
		fmt.Scan(&a[i])
	}
	return n, a
}

// Function to read input from standard input
func inputStringArrayFromStdinWithSize3() (int, []string) {
	var n int
	fmt.Scan(&n)
	a := make([]string, n)
	for i := range a {
		fmt.Scan(&a[i])
	}
	return n, a
}

// Function to read input from standard input
func inputIntMatrixFromStdinWithSize4() (int, int, [][]int) {
	var n, m int
	fmt.Scan(&n, &m)
	a := make([][]int, n)
	for i := range a {
		a[i] = make([]int, m)
		for j := range a[i] {
			fmt.Scan(&a[i][j])
		}
	}
	return n, m, a
}

// Function to read input from standard input
func inputStringMatrixFromStdinWithSize4() (int, int, [][]string) {
	var n, m int
	fmt.Scan(&n, &m)
	a := make([][]string, n)
	for i := range a {
		a[i] = make([]string, m)
		for j := range a[i] {
			fmt.Scan(&a[i][j])
		}
	}
	return n, m, a
}

// Function to read input from standard input
func inputIntArrayFromStdinWithSize4() (int, []int) {
	var n int
	fmt.Scan(&n)
	a := make([]int, n)
	for i := range a {
		fmt.Scan(&a[i])
	}
	return n, a
}

// Function to read input from standard input
func inputStringArrayFromStdinWithSize4() (int, []string) {
	var n int
	fmt.Scan(&n)
	a := make([]string, n)
	for i := range a {
		fmt.Scan(&a[i])
	}
	return n, a
}

// Function to read input from standard input
func inputIntMatrixFromStdinWithSize5() (int, int, [][]int) {
	var n, m int
	fmt.Scan(&n, &m)
	a := make([][]int, n)
	for i := range a {
		a[i] = make([]int, m)
		for j := range a[i] {
			fmt.Scan(&a[i][j])
		}
	}
	return n, m, a
}

// Function to read input from standard input
func inputStringMatrixFromStdinWithSize5() (int, int, [][]string) {
	var n, m int
	fmt.Scan(&n, &m)
	a := make([][]string, n)
	for i := range a {
		a[i] = make([]string, m)
		for j := range a[i] {
			fmt.Scan(&a[i][j])
		}
	}
	return n, m, a
}

// Function to read input from standard input
func inputIntArrayFromStdinWithSize5() (int, []int) {
	var n int
	fmt.Scan(&n)
	a := make([]int, n)
	for i := range a {
		fmt.Scan(&a[i])
	}
	return n, a
}

// Function to read input from standard input
func inputStringArrayFromStdinWithSize5() (int, []string) {
	var n int
	fmt.Scan(&n)
	a := make([]string, n)
	for i := range a {
		fmt.Scan(&a[i])
	}
	return n, a
}

// Function to read input from standard input
func inputIntMatrixFromStdinWithSize6() (int, int, [][]int) {
	var n, m int
	fmt.Scan(&n, &m)
	a := make([][]int, n)
	for i := range a {
		a[i] = make([]int, m)
		for j := range a[i] {
			fmt.Scan(&a[i][j])
		}
	}
	return n, m, a
}

// Function to read input from standard input
func inputStringMatrixFromStdinWithSize6() (int, int, [][]string) {
	var n, m int
	fmt.Scan(&n, &m)
	a := make([][]string, n)
	for i := range a {
		a[i] = make([]string, m)
		for j := range a[i] {
			fmt.Scan(&a[i][j])
		}
	}
	return n, m, a
}

// Function to read input from standard input
func inputIntArrayFromStdinWithSize6() (int, []int) {
	var n int
	fmt.Scan(&n)
	a := make([]int, n)
	for i := range a {
		fmt.Scan(&a[i])
	}
	return n, a
}

// Function to read input from standard input
func inputStringArrayFromStdinWithSize6() (int, []string) {
	var n int
	fmt.Scan(&n)
	a := make([]string, n)
	for i := range a {
		fmt.Scan(&a[i])
	}
	return n, a
}

// Function to read input from standard input
func inputIn