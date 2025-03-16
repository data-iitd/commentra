package main

import (
	"fmt"
	"io/ioutil"
	"os"
	"strconv"
	"strings"
)

func main() {
	var n int
	var A []int
	var B []int
	var C []int
	var i, j int
	var d int
	var str string
	var p int

	str, _ = ioutil.ReadAll(os.Stdin)
	p = 0

	n = getNum(str, &p)
	A = make([]int, n+1)
	B = make([]int, n+1)
	C = make([]int, 10001)

	for i = 1; i <= n; i++ {
		A[i] = getNum(str, &p)
	}

	for j = 1; j <= n; j++ {
		C[A[j]]++
	}

	for i = 1; i <= 10000; i++ {
		C[i] += C[i-1]
	}

	for j = n; j > 0; j-- {
		B[C[A[j]]] = A[j]
		C[A[j]]--
	}

	p = 0
	n--
	for i = 1; i <= n; i++ {
		putNum(B[i], &p)
		str[p] = ' '
		p++
	}
	putNum(B[i], &p)
	str[p] = '\0'

	fmt.Println(string(str))
}

func getNum(str string, p *int) int {
	var n int
	var c int

	n = 0
	for *p < len(str) && str[*p] >= '0' && str[*p] <= '9' {
		n = n*10 + int(str[*p]-'0')
		*p++
	}
	*p++
	return n
}

func putNum(n int, p *int) {
	var d int

	if n < 10 {
		str[*p] = '0' + byte(n)
		*p++
		return
	}
	d = n / 10
	if d != 0 {
		putNum(d, p)
	}
	str[*p] = '0' + byte(n-d*10)
	*p++
}

