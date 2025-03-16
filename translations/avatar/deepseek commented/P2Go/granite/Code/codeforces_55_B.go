
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter the numbers:")
	input, _ := reader.ReadString('\n')
	nums := strings.Split(input, " ")
	for i := range nums {
		nums[i], _ = strconv.ParseInt(nums[i], 10, 64)
	}
	fmt.Println("Enter the operations:")
	input, _ = reader.ReadString('\n')
	operations := strings.Split(input, " ")
	ans := int64(10000000000000000000000000)
	rememberTheNumber(nums, 0, operations, &ans)
	fmt.Println("The smallest number is:", ans)
}

func rememberTheNumber(nums []int64, i int, operations []string, ans *int64) {
	if i >= 3 {
		return
	}
	for j := 0; j < 4; j++ {
		for k := j + 1; k < 4; k++ {
			if nums[j]!= -1 && nums[k]!= -1 {
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

// End of code