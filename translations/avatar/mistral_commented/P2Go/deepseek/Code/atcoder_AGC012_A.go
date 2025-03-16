package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func readInts() []int {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	var result []int
	for scanner.Scan() {
		num, _ := strconv.Atoi(scanner.Text())
		result = append(result, num)
	}
	return result
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	A := readInts()
	sort.Ints(A)
	ans := 0
	for i := len(A) - 2; i >= len(A) - 2*n - 1; i -= 2 {
		ans += A[i]
	}
	fmt.Println(ans)
}
