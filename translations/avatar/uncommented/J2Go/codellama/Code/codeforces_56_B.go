
package main

import (
	"fmt"
	"math"
	"os"
	"strconv"
)

func main() {
	var len int
	var a []int
	var l, r int
	var flag, isTrue bool
	var i int
	var scan *bufio.Scanner
	scan = bufio.NewScanner(os.Stdin)
	scan.Scan()
	len, _ = strconv.Atoi(scan.Text())
	a = make([]int, len)
	for i = 0; i < len; i++ {
		scan.Scan()
		a[i], _ = strconv.Atoi(scan.Text())
	}
	l = 0
	r = 0
	flag = false
	isTrue = false
	for i = 0; i < len; i++ {
		if a[i] != i+1 && !flag {
			l = i + 1
			flag = true
			continue
		}
		if a[i] != i+1 && flag {
			r = i + 1
			if (a[r-1] - a[r-2]) > 0 {
				isTrue = true
				break
			}
		}
	}
	fmt.Println((!isTrue) ? l + " " + r : "0" + " " + "0")
}

