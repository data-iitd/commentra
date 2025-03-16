
package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
)

var (
	n int
	a []int
	s map[int]int
)

func main() {
	set()
	ng := 0
	ok := n
	for ok-ng > 1 {
		k := (ng + ok) / 2
		if isPossible(k) {
			ok = k
		} else {
			ng = k
		}
	}
	fmt.Println(ok)
}

func set() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Scan()
	n, _ = strconv.Atoi(sc.Text())
	a = make([]int, n)
	sc.Scan()
	s = make(map[int]int)
	for i, v := range strings.Split(sc.Text(), " ") {
		a[i], _ = strconv.Atoi(v)
	}
}

func isPossible(k int) bool {
	s = make(map[int]int)
	current := 0
	for _, ai := range a {
		if ai <= current {
			if k == 1 {
				return false
			}
			for s[ai] >= k {
				delete(s, ai)
				ai++
			}
			p := ai - 1
			for {
				if p < 0 {
					return false
				}
				sp := s[p] + 1
				s[p] = sp
				if sp == k {
					delete(s, p)
					p--
				} else {
					break
				}
			}
		}
		current = ai
	}
	return true
}

