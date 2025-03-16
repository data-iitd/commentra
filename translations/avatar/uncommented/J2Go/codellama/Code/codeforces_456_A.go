
package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var n int
	var a, b []int
	var temp int
	var q, w, e int
	var f bool
	var input string
	var scanner *bufio.Scanner
	scanner = bufio.NewScanner(os.Stdin)
	scanner.Scan()
	input = scanner.Text()
	n, _ = strconv.Atoi(input)
	a = make([]int, n)
	b = make([]int, n)
	temp = 0
	q = 0
	w = 0
	e = 0
	f = false
	for i := 0; i < n; i++ {
		scanner.Scan()
		input = scanner.Text()
		a[i], _ = strconv.Atoi(input)
		scanner.Scan()
		input = scanner.Text()
		b[i], _ = strconv.Atoi(input)
		if temp < a[i] {
			if q > b[i] {
				f = true
			}
			q = b[i]
			temp = a[i]
		}
		if temp > a[i] {
			if q < b[i] {
				f = true
			}
			q = b[i]
			temp = a[i]
		}
		if a[i] > w {
			w = a[i]
			if b[i] < e {
				f = true
			}
			e = b[i]
		}
		if a[i] < w {
			if b[i] > e {
				f = true
			}
		}
	}
	if f == true {
		fmt.Println("Happy Alex")
	} else {
		fmt.Println("Poor Alex")
	}
}

