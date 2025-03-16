
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReaderSize(os.Stdin, 1024 * 1024)

	fmt.Println("Enter the number of elements and the divisor")
	line, _ := reader.ReadString('\n')
	line = strings.TrimSpace(line)
	num, k, _ := strings.Split(line, " ")
	num, k = strconv.Atoi(num), strconv.Atoi(k), 0
	arr := make([]int, num)
	fmt.Println("Enter the array of integers")
	line, _ = reader.ReadString('\n')
	line = strings.TrimSpace(line)
	arr = append(arr, strings.Split(line, " ")...)
	for i := 0; i < len(arr); i++ {
		arr[i], _ = strconv.Atoi(arr[i])
	}
	sort.Ints(arr)
	different := make(map[int]bool)
	temp := 0
	for _, x := range arr {
		if x%k!= 0 ||!x/k in different {
			different[x] = true
		}
		temp = max(len(different), temp)
	}
	fmt.Println(temp)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

