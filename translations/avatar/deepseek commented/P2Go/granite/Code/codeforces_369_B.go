
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func getNums(num, t int) []int {
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

func main() {
	// Read input values for n, k, l, r, sa, and sk
	scanner := bufio.NewScanner(os.Stdin)
	var n, k, l, r, sa, sk int
	fmt.Fscanf(scanner, "%d %d %d %d %d %d\n", &n, &k, &l, &r, &sa, &sk)

	// Use the getNums function to calculate the distribution of sk and sa - sk
	ans := getNums(k, sk)
	for _, v := range getNums(n-k, sa-sk) {
		ans = append(ans, v)
	}

	// Print the result as a space-separated string of numbers
	fmt.Println(strings.Join(func() []string {
		s := make([]string, len(ans))
		for i, v := range ans {
			s[i] = strconv.Itoa(v)
		}
		return s
	}(), " "))
}

