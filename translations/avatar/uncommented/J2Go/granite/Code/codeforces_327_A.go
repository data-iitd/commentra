
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	if scanner.Scan() {
		n, _ := strconv.Atoi(scanner.Text())
		arr := make([]int, n)
		for i := 0; i < n; i++ {
			if scanner.Scan() {
				arr[i], _ = strconv.Atoi(scanner.Text())
			}
		}
		max := -1
		for i := 0; i < n; i++ {
			for j := i; j < n; j++ {
				x := 0
				brr := make([]int, n)
				for _, k := range arr {
					brr[x] = k
					x++
				}
				for k := i; k <= j; k++ {
					if brr[k] == 0 {
						brr[k] = 1
					} else {
						brr[k] = 0
					}
				}
				count := checkNo(brr)
				if count > max {
					max = count
				}
			}
		}
		if n == 1 {
			if arr[0] == 1 {
				fmt.Println(0)
			} else {
				fmt.Println(1)
			}
		} else {
			fmt.Println(max)
		}
	}
}

func checkNo(brr []int) int {
	val := 0
	for _, i := range brr {
		if i == 1 {
			val++
		}
	}
	return val
}

// 