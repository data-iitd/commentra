package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	scanner.Scan()
	n := toInt(scanner.Text())
	scanner.Scan()
	levels := toInt(scanner.Text())
	sum := 0
	sum2 := 0
	sum3 := 0
	var arr []int
	var count int

	for i := 0; i < levels; i++ {
		scanner.Scan()
		arr = append(arr, toInt(scanner.Text()))
	}

	scanner.Scan()
	level2 := toInt(scanner.Text())
	level3 := levels + level2
	var arr2 []int

	for i := 0; i < len(arr); i++ {
		arr2 = append(arr2, arr[i])
	}

	for i := len(arr); i < level3; i++ {
		scanner.Scan()
		arr2 = append(arr2, toInt(scanner.Text()))
	}

	var arr3 = make([]int, n)
	j := 0
	for i := 0; i < n; i++ {
		arr3[i] = j + 1
		j++
	}

	for i := 0; i < n; i++ {
		for x := 0; x < len(arr2); x++ {
			if arr3[i] == arr2[x] {
				count++
				break
			}
		}
	}

	if count == n {
		fmt.Println("I become the guy.")
	} else {
		fmt.Println("Oh, my keyboard!")
	}
}

func toInt(s string) int {
	var res int
	for _, c := range s {
		res = res*10 + int(c-'0')
	}
	return res
}

