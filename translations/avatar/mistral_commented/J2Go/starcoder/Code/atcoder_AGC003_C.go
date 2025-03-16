package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Global variables
var (
	NUM int = 100000 + 2
)

// Function to read input
func readInput() int {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	sc.Scan()
	n, _ := strconv.Atoi(sc.Text())
	return n
}

// Function to check if the binary index and the index of the current element have opposite parity
func checkParity(bin int, idx int) bool {
	return (bin%2)!= (idx%2)
}

// Function to calculate the answer
func calculateAnswer(diff int) int {
	return diff / 2
}

// Function to print the answer
func printAnswer(ans int) {
	fmt.Println(ans)
}

// Main function
func main() {
	n := readInput()
	nums := make([]int, n)
	map := make(map[int]int)
	bin := 0
	diff := 0
	for i := 0; i < n; i++ {
		sc := bufio.NewScanner(os.Stdin)
		sc.Split(bufio.ScanWords)
		sc.Scan()
		nums[i], _ = strconv.Atoi(sc.Text())
		map[nums[i]] = i
	}
	for i := 0; i < n; i++ {
		num := nums[i]
		idx := map[num]
		if checkParity(bin, idx) {
			diff++
		}
		bin++
		bin %= 2
	}
	ans := calculateAnswer(diff)
	printAnswer(ans)
}

// 