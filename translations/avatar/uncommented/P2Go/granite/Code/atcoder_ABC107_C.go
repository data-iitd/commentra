
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var (
	N, K int
	lst   []int
	lst_p []int
	lst_m []int
)

func main() {
	N, K = read_int(), read_int()
	lst = read_int_list()
	lst_p = make([]int, 0)
	lst_m = make([]int, 0)
	for i := 0; i < N; i++ {
		if lst[i] == 0 {
			K--
		}
		if lst[i] > 0 {
			lst_p = append(lst_p, lst[i])
		} else if lst[i] < 0 {
			lst_m = append(lst_m, lst[i])
		}
	}
	p, m := 0, 0
	x, y := 0, len(lst_m)-1
	lastx, lasty := len(lst_p), len(lst_m)
	ans := 1000000000
	for j := 0; j <= K; j++ {
		if j > lastx || K-j > lasty {
			continue
		}
		if j == 0 {
			p = 0
		} else {
			p = lst_p[j-1]
		}
		if K-j == 0 {
			m = 0
		} else {
			m = lst_m[lasty-(K-j)]
		}
		ans = min(ans, 2*p+abs(m), p+2*abs(m))
	}
	fmt.Println(ans)
}

func read_int() int {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	var n int
	sc.Scan()
	n, _ = strconv.Atoi(sc.Text())
	return n
}

func read_int_list() []int {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	var n int
	var list []int
	for sc.Scan() {
		n, _ = strconv.Atoi(sc.Text())
		list = append(list, n)
	}
	return list
}

func min(a, b, c int) int {
	m := a
	if m > b {
		m = b
	}
	if m > c {
		m = c
	}
	return m
}

func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}

