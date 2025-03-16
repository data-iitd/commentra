

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func binarySearch(arr []int, key int) int {
	left := 0
	right := len(arr) - 1

	for left < right {
		mid := (left + right) / 2

		if arr[mid] == key {
			return 1
		} else if arr[mid] > key {
			right = mid
		} else {
			left = mid + 1
		}
	}

	return 0
}

func main() {
	reader := bufio.NewReader(os.Stdin)

	fmt.Print("Enter the size of the array: ")
	size, _ := reader.ReadString('\n')
	n, _ := strconv.Atoi(size)

	arr := make([]int, n)

	fmt.Println("Enter", n, "integers:")
	for i := 0; i < n; i++ {
		fmt.Print("Element", i+1, ": ")
		num, _ := reader.ReadString('\n')
		arr[i], _ = strconv.Atoi(num)
	}

	fmt.Print("Enter the number of queries: ")
	q, _ := reader.ReadString('\n')
	queries, _ := strconv.Atoi(q)

	queryArr := make([]int, queries)

	fmt.Println("Enter", queries, "integers to be searched:")
	for i := 0; i < queries; i++ {
		fmt.Print("Query", i+1, ": ")
		num, _ := reader.ReadString('\n')
		queryArr[i], _ = strconv.Atoi(num)
	}

	count := 0
	for _, query := range queryArr {
		if binarySearch(arr, query) == 1 {
			count++
		}
	}

	fmt.Println("Number of queries present in the array:", count)
}

