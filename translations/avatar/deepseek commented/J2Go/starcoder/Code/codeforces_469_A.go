
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
	fmt.Println("Enter the number of levels:")
	n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	fmt.Println("Enter the number of levels completed:")
	levels, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	arr := make([]int, levels)
	fmt.Println("Enter the levels completed:")
	for i := 0; i < levels; i++ {
		arr[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	}
	fmt.Println("Enter the number of levels completed by the second user:")
	level2, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	level3 := levels + level2
	arr2 := make([]int, level3)
	fmt.Println("Enter the levels completed by the second user:")
	for i := 0; i < level3; i++ {
		arr2[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	}
	arr3 := make([]int, n)
	for i := 0; i < n; i++ {
		arr3[i] = i + 1
	}
	count := 0
	for i := 0; i < n; i++ {
		for x := 0; x < level3; x++ {
			if arr3[i] == arr2[x] {
				count++
				break
			}
		}
	}
	if count == n {
		fmt.Println("I become the guy.")
	} else {
		fmt.Println("Oh, my keyboard!")
	}
}

