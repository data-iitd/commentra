
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var (
	low  [200000]int
	high [200000]int
	a    [200000]int
)

func part(a []int, b []int, l int, r int) int {
	var i, j, x, t int

	i = l - 1
	j = r
	x = b[r]

	for {
		for b[i+1] < x {
			i++
		}
		for i < j-1 && x < b[j-1] {
			j--
		}

		if i >= j {
			break
		}

		t = a[i]
		a[i] = a[j]
		a[j] = t
		t = b[i]
		b[i] = b[j]
		b[j] = t
		i++
	}

	t = a[i]
	a[i] = a[r]
	a[r] = t
	t = b[i]
	b[i] = b[r]
	b[r] = t
	return i
}

func quicksort(a []int, b []int, n int) {
	var l, r, v int
	var sp int

	low[0] = 0
	high[0] = n - 1
	sp = 1

	for sp > 0 {
		sp--
		l = low[sp]
		r = high[sp]

		if l >= r {
			continue
		}

		v = part(a, b, l, r)

		if v-l < r-v {
			low[sp] = v + 1
			high[sp] = r
			low[sp+1] = l
			high[sp+1] = v - 1
			sp++
		} else {
			low[sp] = l
			high[sp] = v - 1
			low[sp+1] = v + 1
			high[sp+1] = r
			sp++
		}
	}
}

func main() {
	var n, m int
	var i int
	var a [100006]int
	var b [100006]int
	var cnt int
	var t int

	scanner := bufio.NewScanner(os.Stdin)
	if scanner.Scan() {
		t, _ := strconv.Atoi(scanner.Text())
	}

	for i = 0; i < t; i++ {
		fmt.Fscanf(scanner, "%d %d\n", &n, &m)

		for j := 0; j < m; j++ {
			fmt.Fscanf(scanner, "%d %d\n", &a[j], &b[j])
		}

		quicksort(a[:m], b[:m], m)

		cnt = 0
		t = 0
		for j := 0; j < m; j++ {
			if t <= a[j] {
				t = b[j]
				cnt++
			}
		}

		fmt.Println(cnt)
	}
}

