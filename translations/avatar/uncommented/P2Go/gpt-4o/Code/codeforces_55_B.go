package main

import (
	"fmt"
	"math"
)

func rememberTheNumber(nums []int, i int, operations []string, ans *[]int) {
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
				if i == 2 && nums[k] < (*ans)[0] {
					(*ans)[0] = nums[k]
				}
				rememberTheNumber(nums, i+1, operations, ans)
				nums[j] = s
				nums[k] = t
			}
		}
	}
}

func main() {
	var nums [4]int
	for i := 0; i < 4; i++ {
		fmt.Scan(&nums[i])
	}
	var operations [3]string
	for i := 0; i < 3; i++ {
		fmt.Scan(&operations[i])
	}
	ans := []int{int(math.MaxInt64)}
	rememberTheNumber(nums[:], 0, operations[:], &ans)
	fmt.Println(ans[0])
}

// <END-OF-CODE>
