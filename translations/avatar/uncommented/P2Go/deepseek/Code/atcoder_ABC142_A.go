package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func nextInt() int {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}

func nextInts() []int {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	nums := []int{}
	scanner.Text()
	for _, num := range nums {
		num, _ := strconv.Atoi(num)
		nums = append(nums, num)
	}
	return nums
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	t := 0
	for i := 0; i < n; i++ {
		if (i + 1) & 1 == 1 {
			t += 1
		}
	}
	fmt.Println(float64(t) / float64(n))
}
