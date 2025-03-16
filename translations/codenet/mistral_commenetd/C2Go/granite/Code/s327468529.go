
package main

import (
	"bufio"
	"bytes"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	var n, m int64
	fmt.Fscanf(reader, "%d\n", &n)
	fmt.Fscanf(reader, "%d\n", &m)

	a := make([]int64, n)
	b := make([]int64, n)
	c := make([]int64, n)
	d := make([]int64, n)

	for i := int64(0); i < n; i++ {
		fmt.Fscanf(reader, "%d\n", &a[i])
	}

	for i := int64(0); i < n; i++ {
		fmt.Fscanf(reader, "%d\n", &b[i])
	}

	for i := int64(0); i < m; i++ {
		fmt.Fscanf(reader, "%d\n", &c[i])
	}

	for i := int64(0); i < h; i++ {
		fmt.Fscanf(reader, "%s\n", s[i])
	}

	var q int64
	fmt.Fscanf(reader, "%d\n", &q)

	result := solve()
	fmt.Println(result)
}

func solve() int64 {
	var result int64 = 1
	var pcnt int64 = 0

	cnt := make([]int64, 3)

	for i := int64(0); i < n*3; i++ {
		var v int64
		switch s[i] {
		case 'R':
			v = 0
		case 'G':
			v = 1
		case 'B':
			v = 2
		}
		if cnt[(v+1)%3] > 0 && cnt[(v+2)%3] > 0 {
			result = (result * pcnt) % FOD
			pcnt--
			cnt[(v+1)%3]--
			cnt[(v+2)%3]--
		} else {
			if (cnt[(v+1)%3]+cnt[(v+2)%3]) > cnt[v] {
				result = (result * ((cnt[(v+1)%3] + cnt[(v+2)%3]) - cnt[v])) % FOD
				pcnt++
			}
			cnt[v]++
		}
	}

	for i := int64(1); i <= n; i++ {
		result = (result * i) % FOD
	}

	return result
}
