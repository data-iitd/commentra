package main

import (
	"fmt"
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

	var line [2][1]string
	for i := 0; i < 2; i++ {
		for j := 0; j < n; j++ {
			var input string
			fmt.Scan(&input)
			line[i][0] += input
		}
	}

	number := ""
	for i := 1; i <= n; i++ {
		number += strconv.Itoa(i)
	}

	listA := []string{}
	permutation(listA, number, "")

	sum := 0
	for j := 0; j < len(line); j++ {
		for i := 0; i < len(listA); i++ {
			if listA[i] == line[j][0] {
				if sum == 0 {
					sum += i
				} else {
					sum -= i
				}
			}
		}
	}

	fmt.Println(abs(sum))
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

