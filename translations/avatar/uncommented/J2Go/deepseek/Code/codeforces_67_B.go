package main

import (
	"bufio"
	"fmt"
	"os"
)

type Main struct {
	out   *bufio.Writer
	sc    *bufio.Scanner
}

func (m *Main) Print(a ...interface{}) {
	fmt.Fprint(m.out, a...)
}

func (m *Main) Println(a ...interface{}) {
	fmt.Fprintln(m.out, a...)
}

func (m *Main) Flush() {
	m.out.Flush()
}

func NewMain() *Main {
	return &Main{
		out:   bufio.NewWriter(os.Stdout),
		sc:    bufio.NewScanner(os.Stdin),
	}
}

func (m *Main) main() {
	m.sc.Scan()
	n, _ := strconv.Atoi(m.sc.Text())
	m.sc.Scan()
	k, _ := strconv.Atoi(m.sc.Text())
	bb := make([]int, n)
	for i := 0; i < n; i++ {
		m.sc.Scan()
		bb[i], _ = strconv.Atoi(m.sc.Text())
	}
	aa := make([]int, n)
	m = 0
	for a := n - 1; a >= 0; a-- {
		j := 0
		for bb[a] > 0 {
			if j < len(aa) && aa[j] >= a+k {
				bb[a]--
			}
			j++
		}
		for j_ := m; j_ > j; j_-- {
			aa[j_] = aa[j_-1]
		}
		aa[j] = a
		m++
	}
	for i := 0; i < n; i++ {
		m.Print(aa[i] + 1)
		m.Print(" ")
	}
	m.Println()
}

func main() {
	mainInstance := NewMain()
	mainInstance.main()
	mainInstance.Flush()
}

