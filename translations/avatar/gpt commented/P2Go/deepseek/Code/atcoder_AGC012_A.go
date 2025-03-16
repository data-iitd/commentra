package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

const mod = 1000000007

func readInts() []int {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	var result []int
	for scanner.Scan() {
		num := 0
		for _, ch := range scanner.Text() {
			num = num*10 + int(ch-'0')
		}
		result = append(result, num)
	}
	return result
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	n := 0
	for _, ch := range scanner.Text() {
		n = n*10 + int(ch-'0')
	}
	A := readInts()
	sort.Ints(A)
	ans := 0
	for i := len(A) - 2*n - 1; i >= len(A)-2*n; i -= 2 {
		ans += A[i]
	}
	fmt.Println(ans)
}

