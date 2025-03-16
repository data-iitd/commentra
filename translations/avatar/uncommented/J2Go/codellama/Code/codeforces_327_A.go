
package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	if scanner.Scan() {
		n, _ := strconv.Atoi(scanner.Text())
		arr := make([]int, n)
		for i := 0; i < n; i++ {
			scanner.Scan()
			arr[i], _ = strconv.Atoi(scanner.Text())
		}
		max := int(^uint(0) >> 1)
		for i := 0; i < n; i++ {
			for j := i; j < n; j++ {
				x := 0
				brr := make([]int, n)
				for k := range arr {
					brr[x] = arr[k]
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

