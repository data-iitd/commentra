
package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var n int
	fmt.Scan(&n)
	list := make([]int, n)
	for i := 0; i < n; i++ {
		list[i], _ = strconv.Atoi(strings.Split(string(fmt.Scan()), " ")[i])
	}
	if sum(list) == 1 {
		fmt.Println(list[sum(list)-1])
	} else {
		fmt.Println(list[sum(list)])
	}
}

func sum(list []int) int {
	var sum int
	for _, v := range list {
		sum += v
	}
	return sum
}

