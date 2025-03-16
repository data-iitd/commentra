
package main

import (
	"fmt"
	"os"
	"bufio"
	"strconv"
	"strings"
)

func main() {
	var n int
	fmt.Scan(&n)
	var ara [n]int
	var map = make(map[int]int)
	for i := 0; i < n; i++ {
		var v int
		fmt.Scan(&v)
		ara[i] = v
		if _, ok := map[v]; !ok {
			map[v] = 1
		} else {
			map[v]++
		}
	}
	var max int
	for _, v := range map {
		if v > max {
			max = v
		}
	}
	var mm = make(map[int]int)
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