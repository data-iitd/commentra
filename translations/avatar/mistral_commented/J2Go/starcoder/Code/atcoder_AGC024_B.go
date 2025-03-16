
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read the number of elements in the array P from the standard input
	N, _ := strconv.Atoi(readLine())

	// Initialize an integer array P of size N
	P := make([]int, N)

	// Read each element of P from the standard input and store it in the corresponding index of the array
	for i := 0; i < N; i++ {
		P[i], _ = strconv.Atoi(readLine())
	}

	// Create an empty HashMap to store the indices of the array P corresponding to each unique element
	map := make(map[int]int)

	// Iterate through each element of the array P and add its index to the HashMap
	for i := 0; i < N; i++ {
		map[P[i]] = i
	}

	// Create an empty ArrayList to store the indices of the non-decreasing subsequences
	nglist := make([]int, 0)

	// Iterate through each index i of the array P, where i < N - 1
	for i := 0; i < N - 1; i++ {
		// If the index i corresponds to a smaller element than the next index, add its index to the ArrayList
		if map[P[i]] > map[P[i+1]] {
			nglist = append(nglist, i)
		}
	}

	// If there are no non-decreasing subsequences, print 0 and exit the program
	if len(nglist) == 0 {
		fmt.Println(0)
		return
	}

	// Calculate the answer by finding the minimum length of a non-decreasing subsequence
	ans := min(N - nglist[0] - 1, nglist[len(nglist) - 1] + 1)

	// Iterate through each pair of consecutive indices in the ArrayList nglist and update the answer if necessary
	for i := 0; i < len(nglist) - 1; i++ {
		ans = min(nglist[i] + 1 + N - nglist[i + 1] - 1, ans)
	}

	// Print the answer
	fmt.Println(ans)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func readLine() string {
	buf := bufio.NewReader(os.Stdin)
	str, _ := buf.ReadString('\n')
	return strings.TrimRight(str, "\r\n")
}

