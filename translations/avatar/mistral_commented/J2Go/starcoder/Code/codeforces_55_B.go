
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var min int64 = int64(math.MaxInt64)
	var arr []int64
	var ops []string
	var res int64
	var a []int64
	var i, j, k int
	var sc = bufio.NewScanner(os.Stdin)
	for i = 0; i < 4; i++ {
		sc.Scan()
		arr = append(arr, int64(sc.Text()))
	}
	for i = 0; i < 3; i++ {
		sc.Scan()
		ops = append(ops, sc.Text())
	}
	util(arr, ops, 0, &min)
	fmt.Println(min)
}

func util(arr []int64, ops []string, idx int, min *int64) {
	if idx == 3 {
		*min = int64(math.Min(float64(*min), float64(arr[0])))
		return
	}
	for i := 0; i < len(arr); i++ {
		for j := i + 1; j < len(arr); j++ {
			a = make([]int64, 0)
			for k = 0; k < len(arr); k++ {
				if k!= j && k!= i {
					a = append(a, arr[k])
				}
			}
			if idx < 3 && ops[idx] == "+" {
				res = arr[i] + arr[j]
			} else {
				res = arr[i] * arr[j]
			}
			a = append(a, res)
			util(a, ops, idx+1, min)
		}
	}
}

