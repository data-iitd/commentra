package main

import (
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

func main() {
	n, _ := strconv.Atoi(readLine())
	if n == 1 {
		fmt.Println(0)
		return
	}

	fac_ := primeFactorize(n)
	fac := make(map[int]int)
	for _, v := range fac_ {
		fac[v]++
	}

	ans := 0
	for p, e := range fac {
		x := e
		for i := 1; i < 99999999; i++ {
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

func readLine() string {
	buf := make([]byte, 0, 1000000)
	for {
		line, isPrefix, err := bufio.NewReader(os.Stdin).ReadLine()
		if err != nil {
			panic(err)
		}
		buf = append(buf, line...)
		if !isPrefix {
			break
		}
	}
	return string(buf)
}

func primeFactorize(n int) []int {
	a := make([]int, 0, 1000000)
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

