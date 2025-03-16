
package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	var n int
	var f int
	var a [100]int
	var k int
	var j int
	var i int
	var t int
	var s string
	var err error
	var scanner *bufio.Scanner
	scanner = bufio.NewScanner(os.Stdin)
	scanner.Scan()
	s = scanner.Text()
	n, err = strconv.Atoi(s)
	if err != nil {
		fmt.Println(err)
		return
	}
	for i = 0; i < n; i++ {
		scanner.Scan()
		s = scanner.Text()
		a[i], err = strconv.Atoi(s)
		if err != nil {
			fmt.Println(err)
			return
		}
	}
	for k = 0; k < n; k++ {
		t = a[k]
		for i = 0; i < n; i++ {
			for j = 0; j < n-1; j++ {
				if i != j && t == (a[i]+a[j]) {
					f = 1
					break
				}
			}
			if f == 1 {
				break
			}
		}
		if f == 1 {
			break
		}
	}
	if f == 1 {
		fmt.Println(k+1, j+1, i+1)
	} else {
		fmt.Println(-1)
	}
}

