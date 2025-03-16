package main

import (
	"fmt"
	"strconv"
)

func rememberTheNumber(nums []int, i int, operations []string, ans *int) {
	if i >= 3 {
		return
	}
	for j := 0; j < 4; j++ {
		for k := j + 1; k < 4; k++ {
			if nums[j] != -1 && nums[k] != -1 {
				s := nums[j]
				nums[j] = -1
				t := nums[k]
				if operations[i] == "+" {
					nums[k] = s + t
				} else if operations[i] == "*" {
					nums[k] = s * t
				}
				if i == 2 && nums[k] < *ans {
					*ans = nums[k]
				}
				rememberTheNumber(nums, i+1, operations, ans)
				nums[j] = s
				nums[k] = t
			}
		}
	}
}

func main() {
	var nums []int
	var operations []string
	var input string
	fmt.Scanln(&input)
	for _, numStr := range strings.Split(input, " ") {
		num, _ := strconv.Atoi(numStr)
		nums = append(nums, num)
	}
	fmt.Scanln(&input)
	for _, op := range strings.Split(input, " ") {
		operations = append(operations, op)
	}
	ans := 10000000000000000000000000
	rememberTheNumber(nums, 0, operations, &ans)
	fmt.Println(ans)
}
