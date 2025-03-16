<<<<<<< HEAD

import (
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

// Function to read an integer from the input string
func getNum() int {
	i, _ := strconv.Atoi(*p)
	*p = (*p)[len(*p)-1:]
	return i
}

// Function to write an integer to the output string
func putNum(n int) {
	*p = fmt.Sprintf("%d", n) + *p
}

// Function to perform counting sort
func CountingSort(A []int, B []int, k int, len int) {
	var C [MAX_Ai]int
	for i := 0; i < len; i++ {
		C[A[i]]++
	}
	for i := 1; i < k; i++ {
		C[i] += C[i-1]
	}
	for i := len - 1; i >= 0; i-- {
		B[C[A[i]]-1] = A[i]
		C[A[i]]--
	}
}

func main() {
	// Read the number of integers to be read
	n = getNum()
	// Read the integers from the input string
	for i := 0; i < n; i++ {
		A[i] = getNum()
	}
	// Perform counting sort
	CountingSort(A, B, MAX_Ai, n)
	// Write the sorted integers to the output string
	for i := 0; i < n; i++ {
		putNum(B[i])
	}
	// Write the output string to the standard output
	fmt.Fprint(os.Stdout, strings.TrimRight(str, " "))
=======
package main

import "fmt"

// #define PutChar(c) ; *p = (char)(c); ++p; // Macro to write a character to the output string

// #define MAX_N (2000001) // Maximum number of integers to be read
// #define MAX_Ai (10001)   // Maximum value of an integer
// #define STR_SIZE (10000010) // Size of the input string

func getNum() int { // Function to read an integer from the input string
    var n int
    fmt.Scanf("%d", &n)
    return n
}

func putNum(n int) { // Function to write an integer to the output string
    fmt.Printf("%d ", n)
}

func CountingSort(A []int, B []int, k int, len int) { // Function to perform counting sort
    var i, j, C [MAX_Ai]int
    for i = 0; i < k; i++ {
        C[i] = 0
    }
    for i = 0; i < len; i++ {
        C[A[i]]++
    }
    for i = 1; i < k; i++ {
        C[i] += C[i-1]
    }
    for i = len - 1; i >= 0; i-- {
        B[C[A[i]]-1] = A[i]
        C[A[i]]--
    }
}

func main() {
    var i int
    var n int
    n = getNum()
    for i = 0; i < n; i++ {
        A[i] = getNum()
    }
    CountingSort(A, B, MAX_Ai, n)
    for i = 0; i < n; i++ {
        putNum(B[i])
    }
>>>>>>> 98c87cb78a (data updated)
}

