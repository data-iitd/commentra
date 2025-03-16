package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	m := Main{}
	m.solve()
}

type Main struct {
	n  int
	a  []int
	s  map[int]int
}

func (m *Main) set() {
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	line = strings.TrimSpace(line)
	m.n, _ = strconv.Atoi(line)
	line, _ = reader.ReadString('\n')
	line = strings.TrimSpace(line)
	m.a = stringToIntSlice(line)
	m.s = make(map[int]int)
}

func stringToIntSlice(s string) []int {
	parts := strings.Split(s, " ")
	intSlice := make([]int, len(parts))
	for i, part := range parts {
		intSlice[i], _ = strconv.Atoi(part)
	}
	return intSlice
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
			for len(m.s) > 0 && m.lastKey(m.s) >= ai {
				m.pollLastEntry(m.s)
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

func (m *Main) lastKey(s map[int]int) int {
	key := 0
	for k := range s {
		key = k
		break
	}
	return key
}

func (m *Main) pollLastEntry(s map[int]int) {
	key := m.lastKey(s)
	if s[key] == 1 {
		delete(s, key)
	} else {
		s[key]--
	}
}

