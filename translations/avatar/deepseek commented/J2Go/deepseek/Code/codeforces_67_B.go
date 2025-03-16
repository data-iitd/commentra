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

func (m *Main) Init() {
	m.out = bufio.NewWriter(os.Stdout)
	m.sc = bufio.NewScanner(os.Stdin)
	m.sc.Split(bufio.ScanWords)
}

func (m *Main) main() {
	m.Init()
	n := m.nextInt()
	k := m.nextInt()
	bb := make([]int, n)
	for i := 0; i < n; i++ {
		bb[i] = m.nextInt()
	}

	aa := make([]int, n)
	m := 0

	for a := n - 1; a >= 0; a-- {
		j := 0
		for bb[a] > 0 {
			if j >= len(aa) || aa[j] >= a+k {
				bb[a]--
			}
			j++
		}
		aa = append(aa[:m], append([]int{a}, aa[m:]...)...)
		m++
	}

	for i := 0; i < n; i++ {
		fmt.Fprint(m.out, aa[i]+1, " ")
	}
	fmt.Fprintln(m.out)
	m.out.Flush()
}

func (m *Main) nextInt() int {
	m.sc.Scan()
	num, _ := fmt.Sscanf(m.sc.Text(), "%d", &num)
	return num
}

func main() {
	mainInstance := &Main{}
	mainInstance.main()
}

