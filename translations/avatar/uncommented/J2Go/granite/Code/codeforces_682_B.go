
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter the number of elements:")
	n, _ := strconv.Atoi(reader.ReadLine())
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Println("Enter element", i+1, ":")
		arr[i], _ = strconv.Atoi(reader.ReadLine())
	}
	sort.Ints(arr)
	c := 1
	for i := 0; i < n; i++ {
		if arr[i] >= c {
			c++
		}
	}
	fmt.Println("The result is:", c)
}

// 