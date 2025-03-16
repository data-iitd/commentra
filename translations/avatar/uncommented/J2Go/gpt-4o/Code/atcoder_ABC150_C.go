package main

import (
	"fmt"
	"math"
	"strings"
)

func permutation(list *[]string, target, ans string) {
	if len(target) <= 1 {
		*list = append(*list, ans+target)
	} else {
		for i := 0; i < len(target); i++ {
			permutation(list, target[:i]+target[i+1:], ans+string(target[i]))
		}
	}
}

func main() {
	var n int
	fmt.Scan(&n)

	line := [2][1]string{}
	for i := 0; i < 2; i++ {
		line[i][0] = ""
		for j := 0; j < n; j++ {
			var input string
			fmt.Scan(&input)
			line[i][0] += input
		}
	}

	number := ""
	for i := 1; i <= n; i++ {
		number += fmt.Sprint(i)
	}

	var listA []string
	permutation(&listA, number, "")

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

	fmt.Println(int(math.Abs(float64(sum))))
}

// <END-OF-CODE>
