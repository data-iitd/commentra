
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func check(lis []int, k, mid int) bool {
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
	n, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	k, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	lis := strings.Split(readLine(reader), " ")
	var l []int
	for _, i := range lis {
		a, _ := strconv.Atoi(i)
		l = append(l, a)
	}
	a, b := 1, max(l)
	ans := b
	for a <= b {
		mid := (a + b) / 2
		if check(l, k, mid) {
			ans = mid
			b = mid - 1
		} else {
			a = mid + 1
		}
	}
	fmt.Println(ans)
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return strings.TrimSpace(string(str))
	}
	return ""
}

func max(l []int) int {
	m := l[0]
	for _, i := range l {
		if i > m {
			m = i
		}
	}
	return m
}

