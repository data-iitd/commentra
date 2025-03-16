
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var md []int

func main() {
	in := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(strings.TrimSpace(readLine(in)))
	a := make([]int, n)
	b := make([]int, n)
	temp := 0
	q := 0
	w := 0
	e := 0
	f := false
	for i := 0; i < n; i++ {
		a[i], _ = strconv.Atoi(strings.TrimSpace(readLine(in)))
		b[i], _ = strconv.Atoi(strings.TrimSpace(readLine(in)))
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

func readLine(in *bufio.Reader) string {
	str, _, err := in.ReadLine()
	if err == nil {
		return strings.Trim(string(str), " \r\n")
	}
	return ""
}

