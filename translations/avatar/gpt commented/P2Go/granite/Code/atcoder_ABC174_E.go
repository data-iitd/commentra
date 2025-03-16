
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func check(lis []int, k int, mid int) bool {
	for _, i := range lis {
		if i%mid == 0 {
			k++
		}
		k -= i / mid
	}
	return k >= 0
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(read(reader))
	k, _ := strconv.Atoi(read(reader))
	lis := make([]int, n)
	for i := 0; i < n; i++ {
		lis[i], _ = strconv.Atoi(read(reader))
	}
	a, b := 1, max(lis)
	ans := b
	for a <= b {
		mid := (a + b) / 2
		if check(lis, k, mid) {
			ans = mid
			b = mid - 1
		} else {
			a = mid + 1
		}
	}
	fmt.Println(ans)
}

func read(reader *bufio.Reader) string {
	s, _ := reader.ReadString('\n')
	for i := 0; i < len(s); i++ {
		if s[i] =='' || s[i] == '\n' {
			return s[:i]
		}
	}
	return s
}

func max(lis []int) int {
	ans := lis[0]
	for _, i := range lis {
		if i > ans {
			ans = i
		}
	}
	return ans
}

