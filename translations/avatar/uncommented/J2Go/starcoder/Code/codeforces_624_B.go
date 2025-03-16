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
	n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	arr := make([]int, n)
	fmt.Println("Enter the elements of the array")
	for i := 0; i < n; i++ {
		arr[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	}
	sort.Ints(arr)
	count := arr[n-1]
	for i := n - 2; i >= 0; i-- {
		if arr[i] < arr[i+1] {
			count += arr[i]
		} else {
			for arr[i] >= arr[i+1] {
				arr[i]--
			}
			if arr[i] > 0 {
				count += arr[i]
			}
		}
	}
	fmt.Println(count)
}

