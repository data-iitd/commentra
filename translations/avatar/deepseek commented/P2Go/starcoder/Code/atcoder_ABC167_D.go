
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Read the values of N and K from input
func readInput(reader *bufio.Reader) (int, int) {
	line, _ := reader.ReadString('\n')
	line = strings.TrimSpace(line)
	line = strings.TrimSuffix(line, "\n")
	line = strings.TrimPrefix(line, "N=")
	N, _ := strconv.Atoi(line)
	line, _ = reader.ReadString('\n')
	line = strings.TrimSpace(line)
	line = strings.TrimSuffix(line, "\n")
	line = strings.TrimPrefix(line, "K=")
	K, _ := strconv.Atoi(line)
	return N, K
}

// Insert -1 at the beginning of the list L
func insert(L []int) []int {
	L = append([]int{-1}, L...)
	return L
}

// Initialize the path list with the first element 1
func initPath(L []int) []int {
	return []int{1}
}

// Initialize index tracker to 0
func initInd(L []int) int {
	return 0
}

// Initialize count to 0
func initCount(L []int) int {
	return 0
}

// Initialize current position to 1
func initX(L []int) int {
	return 1
}

// Initialize loop start index to -1
func initT(L []int) int {
	return -1
}

// Initialize flag to indicate loop detection
func initFlag(L []int) bool {
	return false
}

// Initialize a map to keep track of indices of elements in path
func initHash(L []int) map[int]int {
	return make(map[int]int)
}

// Main loop to traverse the path
func traverse(L []int, x int, t int, flag bool, Hash map[int]int) []int {
	// Get the next element in the path
	ne := L[x]

	// Check if the next element is already in the Hash
	if Hash[ne]!= 0 {
		// Loop detected, set flag and record the start index
		flag = true
		t = Hash[ne]
	}

	// Append the next element to the path and update index
	L = append(L, ne)
	Hash[ne] = len(L)

	// Move to the next element
	x = ne
	return L, x, t, flag, Hash
}

// Check if a loop is detected
func checkLoop(L []int, t int, flag bool) bool {
	return flag
}

// If no loop, print the (K-1)-th element of the path
func printPath(L []int, K int) {
	fmt.Println(L[K-1])
}

// If a loop is detected, print the K-th element of the loop
func printLoop(L []int, t int, K int) {
	fmt.Println(L[t+K-1])
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	N, K := readInput(reader)
	L := make([]int, N)
	for i := 0; i < N; i++ {
		line, _ := reader.ReadString('\n')
		line = strings.TrimSpace(line)
		line = strings.TrimSuffix(line, "\n")
		L[i], _ = strconv.Atoi(line)
	}
	L = insert(L)
	path := initPath(L)
	ind := initInd(L)
	count := initCount(L)
	x := initX(L)
	t := initT(L)
	flag := initFlag(L)
	Hash := initHash(L)
	for i := 0; i < N+1; i++ {
		L, x, t, flag, Hash = traverse(L, x, t, flag, Hash)
		if checkLoop(L, t, flag) {
			break
		}
	}
	if checkLoop(L, t, flag) {
		if K < len(L) {
			printPath(L, K)
		} else {
			K = K - len(L)
			K = K % (len(L) - t)
			printLoop(L, t, K)
		}
	} else {
		printPath(L, K)
	}
}

