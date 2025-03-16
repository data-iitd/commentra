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
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter the number of elements in the array")
	n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	fmt.Println("Enter the value of k")
	k, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	a := make([]int, n)
	fmt.Println("Enter the elements of the array")
	for i := 0; i < n; i++ {
		a[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	}
	sort.Ints(a)
	INF := 1e18 + 1
	l := -INF
	r := INF
	for l+1 < r {
		c := (l + r) / 2
		if check(c) {
			l = c
		} else {
			r = c
		}
	}
	fmt.Println(l)
}

func check(x int) bool {
	tot := 0
	for i := 0; i < len(a); i++ {
		now := a[i]
		l := 0
		r := len(a)
		if now >= 0 {
			for l < r {
				c := (l + r) / 2
				if now*a[c] < x {
					l = c + 1
				} else {
					r = c
				}
			}
			tot += l
		} else {
			for l < r {
				c := (l + r) / 2
				if now*a[c] >= x {
					l = c + 1
				} else {
					r = c
				}
			}
			tot += (len(a) - l)
		}
		if int64(a[i])*int64(a[i]) < int64(x) {
			tot--
		}
	}
	if tot/2 < k {
		return true
	}
	return false
}

