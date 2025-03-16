
package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	var n int
	var a []int
	var value int
	var result int
	var pos int
	var flag int

	n, _ = strconv.Atoi(os.Args[1])
	a = make([]int, n)

	for i := 0; i < n; i++ {
		value, _ = strconv.Atoi(os.Args[i+2])
		a[i] = value
	}

	if a[0] > 15 {
		result = 15
	} else {
		for i := 1; i < n; i++ {
			if a[i]-a[i-1] > 15 {
				pos = i - 1
				flag = 1
				break
			}
		}
		if flag == 1 {
			result = a[pos] + 15
		} else {
			result = a[n-1] + 15
		}
	}

	if result > 90 {
		result = 90
	}

	fmt.Println(result)
}

