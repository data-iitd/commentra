package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var n int
	var a []int
	var s map[int]int
	m := new(Main)
	m.set()
	m.solve()
}

type Main struct {
	n int
	a []int
	s map[int]int
}

func (m *Main) set() {
	br := bufio.NewReader(os.Stdin)
	defer br.Flush()
	fmt.Fscan(br, &m.n)
	a := strings.Split(strings.TrimSpace(br.ReadString()), " ")
	m.a = make([]int, len(a))
	for i := 0; i < len(a); i++ {
		m.a[i], _ = strconv.Atoi(a[i])
	}
	m.s = make(map[int]int)
}

func (m *Main) solve() {
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
			for {
				if len(m.s) == 0 {
					return false
				}
				p := m.s[len(m.s)-1]
				if p >= ai {
					m.s[len(m.s)-1] = m.s[len(m.s)-1] - 1
					if m.s[len(m.s)-1] == 0 {
						m.s = m.s[:len(m.s)-1]
					}
					p = p - 1
				} else {
					break
				}
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
					p = p - 1
				} else {
					break
				}
			}
		}
		current = ai
	}
	return true
}

