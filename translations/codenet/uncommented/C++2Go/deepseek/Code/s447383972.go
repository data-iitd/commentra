package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func readInt() int {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	a := make([]int, n)
	for i := 0; i < n; i++ {
		scanner.Scan()
		a[i], _ = strconv.Atoi(scanner.Text())
	}
	sort.Ints(a)
	q := make([]int, n)
	tot := 0
	for i := 0; i < n; i++ {
		if i < n-1 && a[i] == a[i+1] {
			q[tot] = a[i]
			tot++
			i++
		}
	}
	fmt.Println(q[tot-1] * q[tot-2])
}
