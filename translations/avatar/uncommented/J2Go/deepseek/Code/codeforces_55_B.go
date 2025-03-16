package main

import (
	"fmt"
	"math"
	"strconv"
)

var min int64 = math.MaxInt64

func main() {
	var arr []int64
	var ops []string
	scanner := bufio.NewScanner(os.Stdin)
	for i := 0; i < 4; i++ {
		scanner.Scan()
		num, _ := strconv.ParseInt(scanner.Text(), 10, 64)
		arr = append(arr, num)
	}
	scanner.Scan()
	ops = strings.Split(scanner.Text(), " ")
	util(arr, ops, 0)
	fmt.Println(min)
}

func util(arr []int64, ops []string, idx int) {
	if idx == 3 {
		if arr[0] < min {
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

