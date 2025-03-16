package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
)

var sc = bufio.NewScanner(os.Stdin)

func nextInt() int {
	sc.Scan()
	i, e := strconv.Atoi(sc.Text())
	if e != nil {
		panic(e)
	}
	return i
}

func primeFactorize(n int) []int {
	a := []int{}
	for n%2 == 0 {
		a = append(a, 2)
		n /= 2
	}
	f := 3
	for f*f <= n {
		if n%f == 0 {
			a = append(a, f)
			n /= f
		} else {
			f += 2
		}
	}
	if n != 1 {
		a = append(a, n)
	}
	return a
}

func main() {
	sc.Split(bufio.ScanWords)
	n := nextInt()
	if n == 1 {
		fmt.Println(0)
		return
	}
	fac := primeFactorize(n)
	facCount := make(map[int]int)
	for _, v := range fac {
		facCount[v]++
	}
	ans := 0
	for p, e := range facCount {
		x := e
		for i := 1; i <= 99999999; i++ {
			if x >= i {
				x -= i
				ans++
			} else {
				break
			}
		}
	}
	fmt.Println(ans)
}

