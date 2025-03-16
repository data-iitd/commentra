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
	sc := bufio.NewScanner(os.Stdin)
	a := make([]int, 5)
	r := make([]int, 5)
	m := make(map[int]int)
	for i := 0; i < 5; i++ {
		sc.Scan()
		a[i], _ = strconv.Atoi(sc.Text())
		r[i] = a[i] % 10
		if r[i]!= 0 {
			m[10-r[i]] = a[i]
		}
	}
	ans := 0
	if len(m) == 0 {
		for i := 0; i < 5; i++ {
			ans += a[i]
		}
		fmt.Println(ans)
		return
	}
	last := m[max(m)]
	idx := 0
	for i := 0; i < 5; i++ {
		if a[i] == last {
			idx = i
		}
	}
	for i := 0; i < 5; i++ {
		if i!= idx {
			if a[i]%10 == 0 {
				ans += a[i]
			} else {
				ans += a[i] + (10 - r[i])
			}
		}
	}
	ans += last
	fmt.Println(ans)
}

func max(m map[int]int) int {
	max := 0
	for k, v := range m {
		if k > max {
			max = k
		}
	}
	return max
}

