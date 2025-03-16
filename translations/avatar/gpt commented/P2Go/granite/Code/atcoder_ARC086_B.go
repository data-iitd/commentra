
package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"sort"
)

// Define a modulo constant for later use
const mod = 100000007

// Function to read a line of input and strip the newline character
func input() string {
	s, _ := reader.ReadString('\n')
	return s[:len(s)-1]
}

// Function to read an integer from input
func I() int {
	return readInt()
}

// Function to read a list of integers from input
func II() []int {
	return readNInt()
}

// Function to read a list of integers and return it as a list
func III() []int {
	a := make([]int, 0, N)
	for i := 0; i < N; i++ {
		a = append(a, I())
	}
	return a
}

// Function to read a specific format of input based on the number of elements
func Line(N int, num int) [][]int {
	// If N is less than or equal to 0, return an empty list
	if N <= 0 {
		return make([][]int, num)
	}
	// If num is 1, read N integers and return them as a list
	if num == 1 {
		return readNNInt(N)
	}
	// Otherwise, read N tuples of integers and return them as a transposed list
	read_all := make([][]int, N)
	for i := 0; i < N; i++ {
		read_all[i] = readNInt()
	}
	return transposeInt(read_all)
}

// Function to determine the sign of a number
func my_sign(x int) int {
	return (x > 0) - (x < 0)
}

var (
	N int
	a []int
)

var reader *bufio.Reader = bufio.NewReader(os.Stdin)

func readInt() int {
	i, _ := fmt.Fscanf(reader, "%d\n", &N)
	return N
}

func readNInt() []int {
	a := make([]int, 0, N)
	for i := 0; i < N; i++ {
		x := readInt()
		a = append(a, x)
	}
	return a
}

func readNNInt(N int) [][]int {
	a := make([][]int, N)
	for i := 0; i < N; i++ {
		a[i] = readNInt()
	}
	return a
}

func transposeInt(m [][]int) [][]int {
	t := make([][]int, len(m[0]))
	for i := range m {
		for j := range m[i] {
			t[j] = append(t[j], m[i][j])
		}
	}
	return t
}

func main() {
	N = I()
	a = III()

	max_val := 0
	max_sign := 0
	max_index := -1

	for i, a0 := range a {
		if abs(a0) > max_val {
			max_val = abs(a0)
			max_sign = my_sign(a0)
			max_index = i
		}
	}

	if max_sign == 0 {
		fmt.Println(0)
	} else if max_sign == 1 {
		fmt.Println(2 * N - 1)
		for i := 0; i < N; i++ {
			fmt.Printf("%d %d\n", max_index+1, i+1)
		}
		for i := 0; i < N-1; i++ {
			fmt.Printf("%d %d\n", i+1, i+2)
		}
	} else {
		fmt.Println(2 * N - 1)
		for i := 0; i < N; i++ {
			fmt.Printf("%d %d\n", max_index+1, i+1)
		}
		for i := N - 1; i > 0; i-- {
			fmt.Printf("%d %d\n", i+1, i)
		}
	}
}

