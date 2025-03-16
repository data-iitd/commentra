package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Read input values for n, k, l, r, sa, and sk
	n, _ := strconv.Atoi(strings.TrimSpace(os.Args[1]))
	k, _ := strconv.Atoi(strings.TrimSpace(os.Args[2]))
	l, _ := strconv.Atoi(strings.TrimSpace(os.Args[3]))
	r, _ := strconv.Atoi(strings.TrimSpace(os.Args[4]))
	sa, _ := strconv.Atoi(strings.TrimSpace(os.Args[5]))
	sk, _ := strconv.Atoi(strings.TrimSpace(os.Args[6]))

	// Use the get_nums function to calculate the distribution of sk and sa - sk
	ans := get_nums(k, sk) + get_nums(n-k, sa-sk)

	// Print the result as a space-separated string of numbers
	fmt.Println(strings.Trim(strings.Join(strings.Fields(fmt.Sprint(ans)), " "), "[]"))
}

func get_nums(num, t int) []int {
	// This function distributes the value t among num parts.
	// It calculates the base number for each part by dividing t by num.
	// It adds 1 to the base number for the first t % num parts.
	ans := make([]int, num)
	base := t / num
	for i := 0; i < t%num; i++ {
		ans[i] = base + 1
	}
	for i := t % num; i < num; i++ {
		ans[i] = base
	}
	return ans
}

