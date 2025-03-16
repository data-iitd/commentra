package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func binarySearch(arr []int, key int) int {
	left := 0
	right := len(arr) - 1
	mid := 0

	for left <= right {
		mid = (left + right) / 2
		if key == arr[mid] {
			return 1
		} else if key > arr[mid] {
			left = mid + 1
		} else if key < arr[mid] {
			right = mid - 1
		}
	}
	return 0
}

func main() {
	var (
		n, q, k, sum int
		i            int
		arr          []int
	)

	reader := bufio.NewReader(os.Stdin)
	fmt.Fscan(reader, &n)

	for i = 0; i < n; i++ {
		tmp, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
		arr = append(arr, tmp)
	}

	fmt.Fscan(reader, &q)

	for i = 0; i < q; i++ {
		fmt.Fscan(reader, &k)
		if binarySearch(arr, k) == 1 {
			sum++
		}
	}

	fmt.Println(sum)
}

