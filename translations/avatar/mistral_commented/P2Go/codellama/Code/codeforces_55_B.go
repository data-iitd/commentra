
package main

import (
	"fmt"
	"strconv"
	"strings"
)

func rememberTheNumber(nums []int, i int, operations []string, ans []int) {
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
				if i == 2 && nums[k] < ans[0] {
					ans[0] = nums[k]
				}
				rememberTheNumber(nums, i+1, operations, ans)
				nums[j] = s
				nums[k] = t
			}
		}
	}
}

func main() {
	nums := strings.Split(strings.TrimSpace(input()), " ")
	numsInt := make([]int, len(nums))
	for i := 0; i < len(nums); i++ {
		numsInt[i], _ = strconv.Atoi(nums[i])
	}
	operations := strings.Split(strings.TrimSpace(input()), " ")
	ans := make([]int, 1)
	ans[0] = 10000000000000000000000000
	rememberTheNumber(numsInt, 0, operations, ans)
	fmt.Println(ans[0])
}

func input() string {
	var s string
	fmt.Scan(&s)
	return s
}

