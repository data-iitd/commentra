package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type Main struct {
	n    int
	a    []int
	s    map[int]int
}

func main() {
	m := Main{}
	m.solve()
}

func (m *Main) set() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	m.n, _ = strconv.Atoi(scanner.Text())
	scanner.Scan()
	parts := strings.Split(scanner.Text(), " ")
	m.a = make([]int, m.n)
	for i := 0; i < m.n; i++ {
		m.a[i], _ = strconv.Atoi(parts[i])
	}
	m.s = make(map[int]int)
}

func (m *Main) solve() {
	m.set()
	ng := 0
	ok := m.n

	for ok-ng > 1 {
		k := (ng + ok) / 2
		if m.isPossible(k) {
			ok = k
		} else {
			ng = k
		}
	}
	fmt.Println(ok)
}

func (m *Main) isPossible(k int) bool {
	m.s = make(map[int]int)
	current := 0

	for _, ai := range m.a {
		if ai <= current {
			if k == 1 {
				return false
			}
			for len(m.s) > 0 && m.s[m.lastKey()] >= ai {
				delete(m.s, m.lastKey())
			}
			p := ai - 1
			for {
				if p < 0 {
					return false
				}
				m.s[p]++
				if m.s[p] == k {
					delete(m.s, p)
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

func (m *Main) lastKey() int {
	maxKey := 0
	for k := range m.s {
		if k > maxKey {
			maxKey = k
		}
	}
	return maxKey
}

