<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Global variables
var (
	n int
	A [MAX_N]int
	B [MAX_N]int
	str string
	p *string
)

// Constants
const (
	MAX_N = 2000001
	MAX_Ai = 10001
	STR_SIZE = 10000010
)

// Function declarations
func getNum() int {
	var n int
	for (*p >= '0') && (*p <= '9') {
<<<<<<< HEAD
		n = n * 10 + (int)(*p - '0')
=======
		n = n * 10 + int(*p - '0')
>>>>>>> 98c87cb78a (data updated)
		p = p + 1
	}
	p = p + 1
	return n
}

func putNum(n int) {
	var d int
	if n < 10 {
		fmt.Printf("0%d", n)
		return
	}
	d = n / 10
	if d!= 0 {
		putNum(d)
	}
	fmt.Printf("%d", n - (d * 10))
}

func CountingSort(A []int, B []int, k int, len int) {
	var C [MAX_Ai]int
	var i, j int
	for j = 1; j <= len; j++ {
		C[A[j]] = C[A[j]] + 1
	}
	for i = 1; i <= k; i++ {
		C[i] = C[i] + C[i - 1]
	}
	for j = len; j > 0; j-- {
		B[C[A[j]]] = A[j]
		C[A[j]] = C[A[j]] - 1
	}
}

func main() {
	var i int
	var n int
<<<<<<< HEAD
	var str string
	var p *string

	// Read input into the buffer
	str = bufio.NewReader(os.Stdin).ReadString('\n')
	p = &str

	// Get the number of elements
	n = getNum()

	// Read each element into the array A
	for i = 1; i <= n; i++ {
		A[i] = getNum()
	}

	// Sort the array A using Counting Sort
	CountingSort(A, B, MAX_Ai, n)

	// Reset the pointer to the start of the buffer
	p = &str
	n = n - 1

	// Write each sorted element
=======

	reader := bufio.NewReader(os.Stdin)
	str, _ = reader.ReadString('\n')
	p = &str
	n = getNum()
	for i = 1; i <= n; i++ {
		A[i] = getNum()
	}
	CountingSort(A, B, MAX_Ai, n)
	p = &str
	n = n - 1
>>>>>>> 98c87cb78a (data updated)
	for i = 1; i <= n; i++ {
		putNum(B[i])
		fmt.Printf(" ")
	}
	putNum(B[i])
<<<<<<< HEAD

	// Null-terminate the string
	fmt.Printf("\0")

	// Output the sorted string
	fmt.Printf("%s", str)
=======
	fmt.Printf("\n")
>>>>>>> 98c87cb78a (data updated)
}

