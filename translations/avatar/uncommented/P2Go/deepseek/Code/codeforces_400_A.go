package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func readInt() int {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}

func readString() string {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	return scanner.Text()
}

func readInts() []int {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	parts := strings.Split(scanner.Text(), " ")
	ints := make([]int, len(parts))
	for i, part := range parts {
		ints[i], _ = strconv.Atoi(part)
	}
	return ints
}

func readStrings() []string {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	return strings.Split(scanner.Text(), " ")
}

func help(a, b int, l []int) bool {
	tot := [][]int{}
	for i := 0; i < b; i++ {
		tot = append(tot, l[i*a:(i*a)+a])
	}
	for _, row := range tot {
		sum := 0
		for _, val := range row {
			sum += val
		}
		if sum == b {
			return true
		}
	}
	return false
}

func solve() {
	x := readString()
	s := []int{}
	for _, char := range x {
		if char == 'O' {
			s = append(s, 0)
		} else {
			s = append(s, 1)
		}
	}
	tot := [][]int{}
	for i := 1; i <= 12; i++ {
		if 12%i == 0 {
			if help(i, 12/i, s) {
				tot = append(tot, []int{12 / i, i})
			}
		}
	}
	fmt.Print(len(tot), " ")
	for _, pair := range sorted(tot) {
		fmt.Printf("%dx%d ", pair[0], pair[1])
	}
	fmt.Println()
}

func sorted(pairs [][]int) [][]int {
	// Implement a sorting function for 2D slices
	// This is a placeholder for the actual sorting logic
	return pairs
}

func main() {
	numCases := readInt()
	for i := 0; i < numCases; i++ {
		solve()
	}
}
