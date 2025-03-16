package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	x := make([]int, n)
	for i := 0; i < n; i++ {
		x[i], _ = strconv.Atoi(strings.TrimSpace(readLine(reader)))
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
		cnta[a[i]] += 1
	}
	for i := 0; i < len(b); i++ {
		cntb[b[i]] += 1
	}

	vala := 0
	vala1 := 0
	maxCnta := 0
	maxCnta1 := 0
	for i := 0; i < len(a); i++ {
		if maxCnta < cnta[a[i]] {
			vala = a[i]
			maxCnta = cnta[a[i]]
		}
	}
	for i := 0; i < len(a); i++ {
		if maxCnta1 < cnta[a[i]] && vala!= a[i] {
			maxCnta1 = cnta[a[i]]
			vala1 = a[i]
		}
	}

	valb := 0
	valb1 := 0
	maxCntb := 0
	maxCntb1 := 0
	for i := 0; i < len(b); i++ {
		if maxCntb < cntb[b[i]] {
			valb = b[i]
			maxCntb = cntb[b[i]]
		}
	}
	for i := 0; i < len(b); i++ {
		if maxCntb1 < cntb[b[i]] && valb!= b[i] {
			maxCntb1 = cntb[b[i]]
			valb1 = b[i]
		}
	}

	if valb!= vala {
		res := 0
		for i := 0; i < len(a); i++ {
			if a[i]!= vala {
				res += 1
			}
		}
		for i := 0; i < len(b); i++ {
			if b[i]!= valb {
				res += 1
			}
		}
		fmt.Println(res)
	} else {
		resa := 0
		resb := 0
		resa1 := 0
		resb1 := 0
		for i := 0; i < len(a); i++ {
			if a[i]!= vala {
				resa += 1
			}
			if a[i]!= vala1 {
				resa1 += 1
			}
		}
		for i := 0; i < len(b); i++ {
			if b[i]!= valb {
				resb += 1
			}
			if b[i]!= valb1 {
				resb1 += 1
			}
		}
		fmt.Println(min(resa+resb1, resa1+resb))
	}
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == io.EOF {
		return ""
	}

	return strings.TrimRight(string(str), "\r\n")
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

