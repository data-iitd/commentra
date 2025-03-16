package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	var n int
	fmt.Scan(&n)
	ara := make([]int, n)
	m := make(map[int]int)

	for i := 0; i < n; i++ {
		fmt.Scan(&ara[i])
		if _, ok := m[ara[i]]; !ok {
			m[ara[i]] = 1
		} else {
			m[ara[i]]++
		}
	}

	max := 0
	for _, v := range m {
		if v > max {
			max = v
		}
	}

	mm := make(map[int]int)
	for i := 0; i < n; i++ {
		if _, ok := mm[ara[i]]; !ok {
			mm[ara[i]] = 1
			if mm[ara[i]] == max {
				fmt.Println(ara[i])
				break
			}
		} else {
			mm[ara[i]]++
			if mm[ara[i]] == max {
				fmt.Println(ara[i])
				break
			}
		}
	}
}

// 