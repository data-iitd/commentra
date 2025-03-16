
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Defining a constant value for modulo arithmetic
const MOD = 1000000007

// Defining a constant value for maximum integer
const MAX = int(^uint(0) >> 1)

// Defining a constant value for maximum long
const LMAX = int64(^uint64(0) >> 1)

// Defining the length of an array
var len int = 1000001

func main() {
	// Reading the number of elements in the array
	N, _ := strconv.Atoi(readLine())

	// Reading the long value K
	K, _ := strconv.ParseInt(readLine(), 10, 64)

	// Creating an integer array A of size N
	A := make([]int, N)

	// Reading the elements of the array A
	for i := 0; i < N; i++ {
		A[i], _ = strconv.Atoi(readLine())
	}

	// Creating a HashSet named used to store the indices that have already been processed
	used := make(map[int]bool)

	// Creating an integer array named idx to store the position of the current index in the circular array
	idx := make([]int, N)

	// Creating an integer array named pos to store the position of the previous index in the circular array
	pos := make([]int, N)

	// Initializing the variables next and cur
	next, cur := 0, 0

	// Finding the cycle starting point using BFS
	for!used[next] {
		used[next] = true // Adding the current index to the HashSet used
		idx[next] = cur   // Storing the current position in the idx array
		pos[cur] = next   // Storing the previous position in the pos array
		next = A[next]    // Moving to the next index
		cur++             // Incrementing the current position
	}

	a := int64(cur) - int64(idx[next]) // Calculating the length of the cycle
	b := int64(idx[next])              // Calculating the starting position of the cycle in the array
	ans := (10000 * a + K - b + MOD) % a + b // Calculating the answer using the formula

	// Checking if the starting position of the cycle is greater than K, if yes then the answer is K
	if b > K {
		ans = K
	}

	// Printing the position of the answer in the array
	fmt.Println(pos[ans])
}

// Defining the readLine() method to read input from stdin
func readLine() string {
	buf := bufio.NewReader(os.Stdin)
	str, _, _ := buf.ReadLine()
	return strings.TrimRight(string(str), "\r\n")
}

