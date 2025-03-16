package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	var (
		n, k int
		a    []int64
	)
	fs := bufio.NewScanner(os.Stdin)
	fs.Split(bufio.ScanWords)
	fs.Scan()
	n, _ = strconv.Atoi(fs.Text())
	fs.Scan()
	k, _ = strconv.Atoi(fs.Text())
	a = make([]int64, n)
	for i := 0; i < n; i++ {
		fs.Scan()
		a[i], _ = strconv.ParseInt(fs.Text(), 10, 64)
	}
	sort.Slice(a, func(i, j int) bool { return a[i] < a[j] })
	var (
		l, r, c, tot int64 = -1e18, 1e18, 0, 0
	)
	for l+1 < r {
		c = (l + r) / 2
		if check(c) {
			l = c
		} else {
			r = c
		}
	}
	fmt.Println(l)
}

func check(x int64) bool {
	var (
		tot int64 = 0
	)
	for i := 0; i < len(a); i++ {
		now := a[i]
		l, r := 0, len(a)
		if now >= 0 {
			for l < r {
				c := (l + r) / 2
				if now*a[c] < x {
					l = c + 1
				} else {
					r = c
				}
			}
			tot += int64(l)
		} else {
			for l < r {
				c := (l + r) / 2
				if now*a[c] >= x {
					l = c + 1
				} else {
					r = c
				}
			}
			tot += int64(len(a) - l)
		}
		if a[i]*a[i] < x {
			tot--
		}
	}
	if tot/2 < int64(k) {
		return true
	}
	return false
}

