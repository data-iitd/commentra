package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

func main() {
	var t int
	fmt.Scan(&t)
	var s []string
	pqmax := make([]int, 0)
	pqmin := make([]int, 0)
	sumMin := 0
	sumMax := 0
	sumb := 0
	min := 0
	for t > 0 {
		t--
		s = make([]string, 0)
		fmt.Scan(&s)
		if s[0] == "2" {
			ans := min
			ans *= len(pqmin)
			ans -= sumMin
			ans1 := min
			ans1 *= len(pqmax)
			ans1 = sumMax - ans1
			fmt.Println(min, ans+ans1+sumb)
		} else {
			in, _ := strconv.Atoi(s[1])
			sumb += in
			if in > min {
				pqmax = append(pqmax, in)
				sumMax += in
			} else {
				pqmin = append(pqmin, in)
				sumMin += in
			}
			if len(pqmin) > len(pqmax) {
				sumMax += pqmin[0]
				sumMin -= pqmin[0]
				pqmax = append(pqmax, pqmin[0])
				pqmin = pqmin[1:]
			}
			if len(pqmin) < len(pqmax) {
				sumMax -= pqmax[0]
				sumMin += pqmax[0]
				pqmin = append(pqmin, pqmax[0])
				pqmax = pqmax[1:]
			}
			sort.Ints(pqmin)
			sort.Ints(pqmax)
			min = pqmin[0]
		}
	}
}

