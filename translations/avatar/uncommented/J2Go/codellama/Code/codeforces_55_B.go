
package main

import (
	"fmt"
	"math"
)

func main() {
	var min int64 = math.MaxInt64
	arr := []int64{1, 2, 3, 4}
	ops := []string{"+", "-", "*"}
	util(arr, ops, 0)
	fmt.Println(min)
}

func util(arr []int64, ops []string, idx int) {
	if idx == 3 {
		if min > arr[0] {
			min = arr[0]
		}
		return
	}
	for i := 0; i < len(arr); i++ {
		for j := i + 1; j < len(arr); j++ {
			a := []int64{}
			for k := 0; k < len(arr); k++ {
				if k != j && k != i {
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
			util(a, ops, idx+1)
		}
	}
}

