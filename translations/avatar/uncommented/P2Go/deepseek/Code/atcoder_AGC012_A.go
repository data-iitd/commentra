package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

const mod = 1000000007

func readInts() []int {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	var result []int
	for sc.Scan() {
		num, _ := strconv.Atoi(sc.Text())
		result = append(result, num)
	}
	return result
}

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	sc.Scan()
	n, _ := strconv.Atoi(sc.Text())
	sc.Scan()
	A := readInts()
	sort.Ints(A)
	ans := 0
	for i := len(A) - 2*n - 1; i >= len(A)-2*n-1; i -= 2 {
		ans += A[i]
	}
	fmt.Println(ans)
}
