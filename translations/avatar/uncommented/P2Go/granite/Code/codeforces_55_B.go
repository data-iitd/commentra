
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
	var nums []int
	var operations []string
	var ans int64 = 10000000000000000000000000
	for i := 0; i < 3; i++ {
		temp := strings.Split(readLine(reader), " ")
		tempInt, _ := strconv.Atoi(temp[0])
		nums = append(nums, tempInt)
		tempInt, _ = strconv.Atoi(temp[1])
		nums = append(nums, tempInt)
		operations = append(operations, temp[2])
	}
	rememberTheNumber(nums, 0, operations, &ans)
	fmt.Println(ans)
}

func rememberTheNumber(nums []int, i int, operations []string, ans *int64) {
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
				if i == 2 && int64(nums[k]) < *ans {
					*ans = int64(nums[k])
				}
				rememberTheNumber(nums, i+1, operations, ans)
				nums[j] = s
				nums[k] = t
			}
		}
	}
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return strings.Trim(string(str), " \r\n")
	}
	return ""
}
