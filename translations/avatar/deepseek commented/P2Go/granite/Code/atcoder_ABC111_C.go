
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	n, _ := strconv.Atoi(read(reader))
	x := readLine(reader)

	a := make([]int, 0)
	b := make([]int, 0)
	for i := 0; i < n; i++ {
		if i%2 == 0 {
			a = append(a, intValue(x[i]))
		} else {
			b = append(b, intValue(x[i]))
		}
	}

	cnta := make([]int, 100002)
	cntb := make([]int, 100002)
	for _, v := range a {
		cnta[v]++
	}
	for _, v := range b {
		cntb[v]++
	}

	maxCnta := 0
	maxCnta1 := 0
	vala := 0
	vala1 := 0
	for i := 0; i < 100002; i++ {
		if maxCnta < cnta[i] {
			vala = i
			maxCnta = cnta[i]
		}
		if maxCnta1 < cnta[i] && vala!= i {
			maxCnta1 = cnta[i]
			vala1 = i
		}
	}

	maxCntb := 0
	maxCntb1 := 0
	valb := 0
	valb1 := 0
	for i := 0; i < 100002; i++ {
		if maxCntb < cntb[i] {
			valb = i
			maxCntb = cntb[i]
		}
		if maxCntb1 < cntb[i] && valb!= i {
			maxCntb1 = cntb[i]
			valb1 = i
		}
	}

	if valb!= vala {
		res := 0
		for _, v := range a {
			if v!= vala {
				res++
			}
		}
		for _, v := range b {
			if v!= valb {
				res++
			}
		}
		fmt.Println(res)
	} else {
		resa := 0
		resb := 0
		resa1 := 0
		resb1 := 0
		for _, v := range a {
			if v!= vala {
				resa++
			}
			if v!= vala1 {
				resa1++
			}
		}
		for _, v := range b {
			if v!= valb {
				resb++
			}
			if v!= valb1 {
				resb1++
			}
		}
		fmt.Println(min(resa+resb1, resa1+resb))
	}
}

func read(reader *bufio.Reader) string {
	s, _ := reader.ReadString('\n')
	return s
}

func readLine(reader *bufio.Reader) []string {
	s, _ := reader.ReadString('\n')
	s = s[:len(s)-1]
	return strings.Split(s, " ")
}

func intValue(s string) int {
	r, _ := strconv.Atoi(s)
	return r
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
