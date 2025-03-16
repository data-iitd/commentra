package main

import (
	"fmt"
)

type Main struct {
	out    *bufio.Writer
	scanner *bufio.Scanner
}

func (m *Main) Flush() {
	m.out.Flush()
}

func main() {
	m := &Main{
		scanner: bufio.NewScanner(os.Stdin),
		out:     bufio.NewWriter(os.Stdout),
	}
	m.main()
	m.Flush()
}

func (m *Main) main() {
	m.scanner.Scan()
	n, _ := strconv.Atoi(m.scanner.Text())
	m.scanner.Scan()
	k, _ := strconv.Atoi(m.scanner.Text())
	bb := make([]int, n)
	for i := 0; i < n; i++ {
		m.scanner.Scan()
		bb[i], _ = strconv.Atoi(m.scanner.Text())
	}
	aa := make([]int, n)
	m := 0
	for a := n - 1; a >= 0; a-- {
		for bb[a] > 0 {
			if m >= a+k {
				bb[a]--
			}
			m++
		}
		aa[m] = a
	}
	for i := 0; i < n; i++ {
		fmt.Fprint(m.out, aa[i]+1, " ")
	}
	fmt.Fprintln(m.out)
}

