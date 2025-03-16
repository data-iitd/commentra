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
	n, _ := strconv.Atoi(sc.Text())
	m := make(map[int]int)
	for i := 0; i < n; i++ {
		num, _ := strconv.Atoi(sc.Text())
		if _, ok := m[num]; ok {
			m[num]++
		} else {
			if _, ok := m[num-1]; ok {
				m[num-1]--
			} else {
				m[num] = 1
			}
		}
	}
	ans := 0
	for _, v := range m {
		ans += v
	}
	fmt.Println(ans)
}

