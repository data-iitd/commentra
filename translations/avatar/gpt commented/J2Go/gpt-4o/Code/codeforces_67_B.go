package main

import (
	"fmt"
)

type Main struct {
}

func (m *Main) main() {
	var n, k int
	fmt.Scan(&n, &k)

	bb := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&bb[i])
	}

	aa := make([]int, n)
	mCount := 0

	for a := n - 1; a >= 0; a-- {
		j := 0
		for bb[a] > 0 {
			if j < mCount && aa[j] >= a+k {
				bb[a]--
			}
			j++
		}
		for j_ := mCount; j_ > j; j_-- {
			aa[j_] = aa[j_-1]
		}
		aa[j] = a
		mCount++
	}

	for i := 0; i < n; i++ {
		fmt.Print(aa[i] + 1, " ")
	}
	fmt.Println()
}

func main() {
	o := &Main{}
	o.main()
}

// <END-OF-CODE>
