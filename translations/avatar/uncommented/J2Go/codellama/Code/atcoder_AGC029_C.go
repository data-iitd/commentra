
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
	var n int
	fmt.Scan(&n)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}
	sort.Ints(a)
	var s map[int]int
	s = make(map[int]int)
	var ng int
	var ok int
	ok = n
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

func isPossible(k int) bool {
	s = make(map[int]int)
	current := 0
	for _, ai := range a {
		if ai <= current {
			if k == 1 {
				return false
			}
			for !s.isEmpty() && s.lastKey() >= ai {
				s.pollLastEntry()
			}
			p := ai - 1
			for true {
				if p < 0 {
					return false
				}
				sp := s.getOrDefault(p, 0) + 1
				s.put(p, sp)
				if sp == k {
					s.remove(p)
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

func (s map[int]int) isEmpty() bool {
	return len(s) == 0
}

func (s map[int]int) lastKey() int {
	var lastKey int
	for k := range s {
		lastKey = k
	}
	return lastKey
}

func (s map[int]int) getOrDefault(key int, defaultValue int) int {
	if value, ok := s[key]; ok {
		return value
	}
	return defaultValue
}

func (s map[int]int) put(key int, value int) {
	s[key] = value
}

func (s map[int]int) remove(key int) {
	delete(s, key)
}

