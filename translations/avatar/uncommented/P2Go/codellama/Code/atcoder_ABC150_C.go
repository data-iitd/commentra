package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var n int
	fmt.Scan(&n)
	orig := [][]int{}
	for i := 1; i <= n; i++ {
		orig = append(orig, []int{i})
	}
	for i := 2; i <= n; i++ {
		for j := 0; j < len(orig); j++ {
			for k := 0; k < len(orig[j]); k++ {
				orig[j] = append(orig[j], i+orig[j][k])
			}
		}
	}
	var p, q []int
	fmt.Scan(&p)
	fmt.Scan(&q)
	pn := 0
	qn := 0
	for i := 0; i < len(orig); i++ {
		if strings.Join(strings.Fields(fmt.Sprint(orig[i])), " ") == strings.Join(strings.Fields(fmt.Sprint(p)), " ") {
			pn = i
		}
		if strings.Join(strings.Fields(fmt.Sprint(orig[i])), " ") == strings.Join(strings.Fields(fmt.Sprint(q)), " ") {
			qn = i
		}
	}
	fmt.Println(abs(pn - qn))
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

