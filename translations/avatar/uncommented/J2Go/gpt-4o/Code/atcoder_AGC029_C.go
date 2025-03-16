package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

type Main struct {
	n int
	a []int
	s map[int]int
}

func main() {
	m := Main{}
	m.solve()
}

func (m *Main) set() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscan(reader, &m.n)
	m.a = make([]int, m.n)
	for i := 0; i < m.n; i++ {
		fmt.Fscan(reader, &m.a[i])
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
			for len(m.s) > 0 && m.lastKey() >= ai {
				delete(m.s, m.lastKey())
			}
			p := ai - 1
			for {
				if p < 0 {
					return false
				}
				sp := m.s[p] + 1
				m.s[p] = sp
				if sp == k {
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
	keys := make([]int, 0, len(m.s))
	for k := range m.s {
		keys = append(keys, k)
	}
	sort.Ints(keys)
	if len(keys) == 0 {
		return -1 // or some other value indicating no keys
	}
	return keys[len(keys)-1]
}

// <END-OF-CODE>
