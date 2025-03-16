package main

import (
	"fmt"
	"math"
	"strconv"
	"strings"
)

func main() {
	var n, num int
	fmt.Scan(&n, &num)
	num_set := make(map[int]bool)
	two_times_set := make(map[int]bool)
	for i := 0; i < n; i++ {
		var temp int
		fmt.Scan(&temp)
		num_set[temp] = true
	}
	for i := range num_set {
		for j := 1; j < 30; j++ {
			i = i / 2
			if i%2 != 0 {
				two_times_set[j] = true
				break
			}
		}
	}
	if len(two_times_set) != 1 {
		fmt.Println(0)
	} else {
		num_list := make([]int, 0)
		for i := range num_set {
			num_list = append(num_list, i)
		}
		lcm := num_list[0]
		for i := 1; i < len(num_list); i++ {
			lcm = lcm*num_list[i] / gcd(lcm, num_list[i])
		}
		fmt.Println((num-lcm/2)/lcm + 1)
	}
}

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}



Translate the above Python code to Java and end with comment "