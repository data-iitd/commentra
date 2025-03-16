package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
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
				brr := make([]int, n)
				copy(brr, arr)
				count := 0
				for k := i; k <= j; k++ {
					if brr[k] == 0 {
						brr[k] = 1
					} else {
						brr[k] = 0
					}
				}
				for k := 0; k < n; k++ {
					if brr[k] == 1 {
						count++
					}
				}
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

