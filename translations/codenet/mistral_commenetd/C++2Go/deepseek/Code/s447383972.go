package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

const N = 200010

var (
	a    [N]int
	q    [N]int
	n, tot int
)

func read() int {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}

func write(x int) {
	fmt.Print(x)
}

func writeln(x int) {
	fmt.Println(x)
}

func main() {
	n = read()
	for i := 1; i <= n; i++ {
		a[i] = read()
	}
	sort.Ints(a[:n+1])
	for i := 1; i <= n; i++ {
		if a[i] == a[i+1] {
			q[tot] = a[i]
			tot++
			i++
		}
	}
	writeln(q[tot-1] * q[tot-2])
}
