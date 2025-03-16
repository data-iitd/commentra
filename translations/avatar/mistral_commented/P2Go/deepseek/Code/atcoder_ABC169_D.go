package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

const (
	INF = 999999999999999999999999
	MOD = 1000000007
)

var (
	reader = bufio.NewReader(os.Stdin)
	writer = bufio.NewWriter(os.Stdout)
)

func readInt() int {
	numStr, _ := reader.ReadString('\n')
	num, _ := strconv.Atoi(strings.TrimSpace(numStr))
	return num
}

func primeFactorize(n int) []int {
	var a []int
	for n%2 == 0 {
		a = append(a, 2)
		n /= 2
	}
	for f := 3; f*f <= n; f += 2 {
		if n%f == 0 {
			a = append(a, f)
			n /= f
		}
	}
	if n > 1 {
		a = append(a, n)
	}
	return a
}

func factorial(n int) []int {
	return []int{}
}

func main() {
	defer writer.Flush()

	n := readInt()
	if n == 1 {
		fmt.Fprintln(writer, 0)
		return
	}

	fac := primeFactorize(n)
	counter := make(map[int]int)
	for _, p := range fac {
		counter[p]++
	}

	ans := 0
	for p, e := range counter {
		x := e
		for i := 1; ; i++ {
			if x >= i {
				x -= i
				ans++
			} else {
				break
			}
		}
	}

	fmt.Fprintln(writer, ans)
}
