package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	n := nextInt(sc)

	a := make([]int, 33)
	for i := 0; i < n; i++ {
		x := nextLong(sc)
		a[rec(x)]++
	}

	var answer float64
	for i := 0; i < len(a); i++ {
		summ := (1 + float64(a[i]-1)) / 2.0 * float64(a[i]-1)
		answer += summ
	}

	fmt.Println(int64(answer))
}

func rec(x int64) int {
	answer := 0
	for k := 31; k >= 0; k-- {
		if (x & (1 << k)) != 0 {
			answer++
		}
	}
	return answer
}

func nextInt(sc *bufio.Scanner) int {
	sc.Scan()
	var x int
	fmt.Sscan(sc.Text(), &x)
	return x
}

func nextLong(sc *bufio.Scanner) int64 {
	sc.Scan()
	var x int64
	fmt.Sscan(sc.Text(), &x)
	return x
}
