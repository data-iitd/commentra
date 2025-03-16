
package main

import (
	"fmt"
	"math"
	"strconv"
)

func permutation(list []string, target string, ans string) []string {
	if len(target) <= 1 {
		list = append(list, ans+target)
	} else {
		for i := 0; i < len(target); i++ {
			permutation(list, target[:i]+target[i+1:], ans+string(target[i]))
		}
	}
	return list
}

func main() {
	var n int
	fmt.Scan(&n)
	line := make([]string, 2)
	for i := 0; i < 2; i++ {
		line[i] = ""
		for j := 0; j < n; j++ {
			line[i] += string(<-fmt.Scan())
		}
	}
	number := ""
	for i := 1; i <= n; i++ {
		number += strconv.Itoa(i)
	}
	listA := make([]string, 0)
	permutation(listA, number, "")
	sum := 0
	for j := 0; j < len(line); j++ {
		for i := 0; i < len(listA); i++ {
			if listA[i] == line[j] {
				if sum == 0 {
					sum += i
				} else {
					sum -= i
				}
			}
		}
	}
	fmt.Println(math.Abs(float64(sum)))
}

