package main

import (
	"fmt"
	"math"
)

var min int64 = math.MaxInt64

func main() {
	var sc = newScanner()
	min = math.MaxInt64
	arr := make([]int64, 0)

	for i := 0; i < 4; i++ {
		arr = append(arr, sc.nextInt64())
	}

	ops := make([]string, 3)
	for i := 0; i < 3; i++ {
		ops[i] = sc.next()
	}

	util(arr, ops, 0)
	fmt.Println(min)
}

func util(arr []int64, ops []string, idx int) {
	if idx == 3 {
		min = int64(math.Min(float64(min), float64(arr[0])))
		return
	}

	for i := 0; i < len(arr); i++ {
		for j := i + 1; j < len(arr); j++ {
			a := make([]int64, 0)
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

type scanner struct {
	bufScanner *bufio.Scanner
}

func newScanner() *scanner {
	bufScanner := bufio.NewScanner(os.Stdin)
	bufScanner.Split(bufio.ScanWords)
	return &scanner{
		bufScanner: bufScanner,
	}
}

func (sc *scanner) nextInt64() int64 {
	sc.bufScanner.Scan()
	num, err := strconv.ParseInt(sc.bufScanner.Text(), 10, 64)
	if err != nil {
		fmt.Println("Failed to scan next int64:", err)
	}
	return num
}
