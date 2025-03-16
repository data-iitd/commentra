package main

import (
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

func main() {
	var n int
	fmt.Scan(&n)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	r := make([]string, 0)
	m := 0
	for i := 1; i < n; i++ {
		if math.Abs(float64(a[m])) < math.Abs(float64(a[i])) {
			m = i
		}
	}

	for i := 0; i < n; i++ {
		if a[m] >= 0 != a[i] >= 0 {
			r = append(r, strconv.Itoa(m+1)+" "+strconv.Itoa(i+1))
		}
	}

	if a[m] >= 0 {
		for i := 1; i < n; i++ {
			r = append(r, strconv.Itoa(i+1)+" "+strconv.Itoa(i+2))
		}
	} else {
		for i := n; i > 1; i-- {
			r = append(r, strconv.Itoa(i)+" "+strconv.Itoa(i-1))
		}
	}

	fmt.Println(len(r))
	for _, v := range r {
		fmt.Println(v)
	}
}

