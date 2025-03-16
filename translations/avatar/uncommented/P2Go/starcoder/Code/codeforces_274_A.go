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
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter the number of elements in the array")
	num, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	fmt.Println("Enter the elements of the array")
	arr := make([]int, num)
	for i := 0; i < num; i++ {
		arr[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	}
	fmt.Println("Enter the value of k")
	k, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
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

