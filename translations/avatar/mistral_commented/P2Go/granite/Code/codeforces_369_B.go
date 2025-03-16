

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func getNums(num, t int) []int {
	ans := make([]int, num)
	for i := range ans {
		if i < t%num {
			ans[i] = t/num + 1
		} else {
			ans[i] = t / num
		}
	}
	return ans
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	const initialBufSize = 4096
	const maxBufSize = 1000000
	scanner.Buffer(make([]byte, initialBufSize), maxBufSize)
	scanner.Split(bufio.ScanWords)
	var n, k, l, r, sa, sk int
	scanner.Scan()
	n, _ = strconv.Atoi(scanner.Text())
	scanner.Scan()
	k, _ = strconv.Atoi(scanner.Text())
	scanner.Scan()
	l, _ = strconv.Atoi(scanner.Text())
	scanner.Scan()
	r, _ = strconv.Atoi(scanner.Text())
	scanner.Scan()
	sa, _ = strconv.Atoi(scanner.Text())
	scanner.Scan()
	sk, _ = strconv.Atoi(scanner.Text())
	ans := getNums(k, sk)
	for i := 0; i < n-k; i++ {
		ans = append(ans, getNums(n-k, sa-sk)[i])
	}
	fmt.Println(strings.Join(func() []string {
		s := make([]string, len(ans))
		for i := range ans {
			s[i] = strconv.Itoa(ans[i])
		}
		return s
	}(), " "))
}

