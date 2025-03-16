
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
	fmt.Println("Enter the number of elements in the array")
	n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	fmt.Println("Enter the number of levels in the array")
	levels, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	arr := make([]int, levels)
	for i := 0; i < levels; i++ {
		fmt.Println("Enter the element")
		arr[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	}
	fmt.Println("Enter the number of elements in the second array")
	level2, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	arr2 := make([]int, level2)
	for i := 0; i < level2; i++ {
		fmt.Println("Enter the element")
		arr2[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	}
	arr3 := make([]int, n)
	for i := 0; i < n; i++ {
		arr3[i] = i + 1
	}
	count := 0
	for i := 0; i < n; i++ {
		for x := 0; x < len(arr2); x++ {
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

