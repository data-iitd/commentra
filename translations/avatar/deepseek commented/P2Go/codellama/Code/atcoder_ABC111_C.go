
package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var n int
	fmt.Scan(&n)
	x := make([]int, n)
	for i := 0; i < n; i++ {
		x[i], _ = strconv.Atoi(strings.Split(fmt.Scanln(), " ")[i])
	}

	a := make([]int, 0)
	b := make([]int, 0)
	for i := 0; i < n; i++ {
		if i%2 == 0 {
			a = append(a, x[i])
		} else {
			b = append(b, x[i])
		}
	}

	cnta := make([]int, 100002)
	cntb := make([]int, 100002)
	for i := 0; i < len(a); i++ {
		cnta[a[i]]++
	}
	for i := 0; i < len(b); i++ {
		cntb[b[i]]++
	}

	vala := 0
	vala1 := 0
	maxCnta := 0
	maxCnta1 := 0
	for i := 0; i < len(cnta); i++ {
		if maxCnta < cnta[i] {
			vala = i
			maxCnta = cnta[i]
		}
	}
	for i := 0; i < len(cnta); i++ {
		if maxCnta1 < cnta[i] && vala != i {
			maxCnta1 = cnta[i]
			vala1 = i
		}
	}

	valb := 0
	valb1 := 0
	maxCntb := 0
	maxCntb1 := 0
	for i := 0; i < len(cntb); i++ {
		if maxCntb < cntb[i] {
			valb = i
			maxCntb = cntb[i]
		}
	}
	for i := 0; i < len(cntb); i++ {
		if maxCntb1 < cntb[i] && valb != i {
			maxCntb1 = cntb[i]
			valb1 = i
		}
	}

	if valb != vala {
		res := 0
		for i := 0; i < len(a); i++ {
			if a[i] != vala {
				res++
			}
		}
		for i := 0; i < len(b); i++ {
			if b[i] != valb {
				res++
			}
		}
		fmt.Println(res)
	} else {
		resa := 0
		resb := 0
		resa1 := 0
		resb1 := 0
		for i := 0; i < len(a); i++ {
			if a[i] != vala {
				resa++
			}
			if a[i] != vala1 {
				resa1++
			}
		}
		for i := 0; i < len(b); i++ {
			if b[i] != valb {
				resb++
			}
			if b[i] != valb1 {
				resb1++
			}
		}
		fmt.Println(min(resa+resb1, resa1+resb))
	}
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

