package main

import (
	"bufio"
	"fmt"
	"os"
)

type Main struct {
	out *bufio.Writer
}

func NewMain() *Main {
	return &Main{out: bufio.NewWriter(os.Stdout)}
}

func (m *Main) Print(a ...interface{}) {
	fmt.Fprint(m.out, a...)
}

func (m *Main) Println() {
	fmt.Fprintln(m.out)
}

func (m *Main) Flush() {
	m.out.Flush()
}

func main() {
	main := NewMain()
	defer main.Flush()
	main.main()
}

func (m *Main) main() {
	var n, k int
	fmt.Scan(&n, &k)

	bb := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&bb[i])
	}

	aa := make([]int, n)
	m := 0

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
		main.Print(aa[i] + 1, " ")
	}
	main.Println()
}
