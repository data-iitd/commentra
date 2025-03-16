package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	parts := strings.Split(scanner.Text(), " ")
	n, _ := strconv.Atoi(parts[0])
	m, _ := strconv.Atoi(parts[1])
	x, _ := strconv.Atoi(parts[2])

	c := make([][]int, n)
	for i := 0; i < n; i++ {
		scanner.Scan()
		nums := strings.Split(scanner.Text(), " ")
		c[i] = make([]int, m+1)
		for j := 0; j <= m; j++ {
			c[i][j], _ = strconv.Atoi(nums[j])
		}
	}

	pre := make([]int, n)
	for i := 0; i < n; i++ {
		pre[i] = i
	}

	l := [][]int{}
	rem := []int{}
	ans := 0

	for i := 1; i <= n; i++ {
		for _, j := range combinations(pre, i) {
			l = append(l, j)
		}
	}

	for i := 1; i <= m; i++ {
		for j, k := range l {
			ca := 0
			for _, ii := range k {
				ca += c[ii][i]
			}
			if ca < x {
				rem = append([]int{j}, rem...)
			}
		}
		if len(rem) > 0 {
			for _, j := range rem {
				l = append(l[:j], l[j+1:]...)
			}
			rem = []int{}
		}
		if len(l) == 0 {
			fmt.Println(-1)
			return
		}
	}

	for _, i := range l {
		ca := 0
		for _, j := range i {
			ca += c[j][0]
		}
		if ans == 0 {
			ans = ca
		} else {
			ans = min(ans, ca)
		}
	}

	fmt.Println(ans)
}

func combinations(arr []int, k int) [][]int {
	var result [][]int
	var helper func([]int, int)
	helper = func(arr []int, k int) {
		if k == 0 {
			result = append(result, append([]int(nil), arr...))
		} else {
			for i := 0; i < len(arr); i++ {
				helper(arr[i+1:], k-1)
			}
		}
	}
	helper(arr, k)
	return result
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

