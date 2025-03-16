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
 m := &Main{}
 m.solve()
}

func (m *Main) set() {
 reader := bufio.NewReader(os.Stdin)
 line, _ := reader.ReadString('\n')
 line = strings.TrimSpace(line)
 m.n, _ = strconv.Atoi(line)
 line, _ = reader.ReadString('\n')
 line = strings.TrimSpace(line)
 m.a = []int{}
 for _, s := range strings.Split(line, " ") {
 num, _ := strconv.Atoi(s)
 m.a = append(m.a, num)
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
 lastKey := 0
 for k := range m.s {
 lastKey = k
 break
 }
 return lastKey
}

