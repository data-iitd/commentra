package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var min int64 = 1 << 63 - 1
	var arr []int64
	var ops []string
	sc := bufio.NewScanner(os.Stdin)
	for i := 0; i < 4; i++ {
		a, _ := strconv.ParseInt(sc.Text(), 10, 64)
		arr = append(arr, a)
		sc.Scan()
	}
	for i := 0; i < 3; i++ {
		ops = append(ops, sc.Text())
		sc.Scan()
	}
	util(arr, ops, 0, min)
	fmt.Println(min)
}

func util(arr []int64, ops []string, idx int, min int64) {
	if idx == 3 {
		min = min(min, arr[0])
		return
	}
	for i := 0; i < len(arr); i++ {
		for j := i + 1; j < len(arr); j++ {
			a := make([]int64, 0)
			for k := 0; k < len(arr); k++ {
				if k!= j && k!= i {
					a = append(a, arr[k])
				}
			}
			var res int64
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

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

