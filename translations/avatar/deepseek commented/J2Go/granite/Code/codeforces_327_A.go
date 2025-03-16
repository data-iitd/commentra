
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
	fmt.Println("Enter the size of the array:")
	size, _ := reader.ReadString('\n')
	size = strings.TrimSpace(size)
	n, _ := strconv.Atoi(size)
	arr := make([]int, n)
	fmt.Println("Enter the elements of the array:")
	for i := 0; i < n; i++ {
		element, _ := reader.ReadString('\n')
		element = strings.TrimSpace(element)
		arr[i], _ = strconv.Atoi(element)
	}
	max := -1000000000
	for i := 0; i < n; i++ {
		for j := i; j < n; j++ {
			brr := make([]int, n)
			copy(brr, arr)
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

func checkNo(brr []int) int {
	val := 0
	for _, i := range brr {
		if i == 1 {
			val++
		}
	}
	return val
}

