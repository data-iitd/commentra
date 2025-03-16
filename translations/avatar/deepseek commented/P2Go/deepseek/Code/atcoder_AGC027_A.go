package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	parts := strings.Split(scanner.Text(), " ")
	n, _ := strconv.Atoi(parts[0])
	x, _ := strconv.Atoi(parts[1])

	scanner.Scan()
	numsStr := scanner.Text()
	nums := []int{}
	for _, numStr := range strings.Split(numsStr, " ") {
		num, _ := strconv.Atoi(numStr)
		nums = append(nums, num)
	}

	sort.Ints(nums)

	ans := 0
	if nums[0] > x {
		fmt.Println(0)
		return
	}

	for _, num := range nums {
		if num > x {
			x = 0
			break
		}
		x -= num
		ans += 1
	}

	if x != 0 {
		ans -= 1
	}

	fmt.Println(ans)
}

