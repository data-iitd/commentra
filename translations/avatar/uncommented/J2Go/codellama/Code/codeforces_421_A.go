
package main

import (
	"fmt"
	"math/big"
	"os"
	"strconv"
	"strings"
)

func main() {
	var n, a, b int
	fmt.Scan(&n, &a, &b)
	list1 := make([]int, a)
	list2 := make([]int, b)
	for i := 0; i < a; i++ {
		fmt.Scan(&list1[i])
	}
	for i := 0; i < b; i++ {
		fmt.Scan(&list2[i])
	}
	for i := 0; i < n; i++ {
		if list1[i] == i+1 {
			fmt.Printf("%d ", 1)
		} else {
			fmt.Printf("%d ", 2)
		}
	}
}

