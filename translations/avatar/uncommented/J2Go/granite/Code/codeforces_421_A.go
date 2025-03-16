
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
	var n, a, b int
	fmt.Fscanf(reader, "%d %d %d\n", &n, &a, &b)
	var list1 []int
	var list2 []int
	for i := 0; i < a; i++ {
		var tmp int
		fmt.Fscanf(reader, "%d", &tmp)
		list1 = append(list1, tmp)
	}
	for i := 0; i < b; i++ {
		var tmp int
		fmt.Fscanf(reader, "%d", &tmp)
		list2 = append(list2, tmp)
	}
	for i := 1; i <= n; i++ {
		if contains(list1, i) {
			fmt.Printf("1 ")
		} else {
			fmt.Printf("2 ")
		}
	}
	fmt.Println()
}

func contains(s []int, e int) bool {
	for _, a := range s {
		if a == e {
			return true
		}
	}
	return false
}

