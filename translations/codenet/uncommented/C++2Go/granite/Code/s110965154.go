
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

	fmt.Println("Enter the number of elements:")
	num, _ := reader.ReadString('\n')
	num = strings.TrimSpace(num)
	n, _ := strconv.Atoi(num)

	fmt.Println("Enter the elements:")
	var arr []int
	for i := 0; i < n; i++ {
		input, _ := reader.ReadString('\n')
		input = strings.TrimSpace(input)
		val, _ := strconv.Atoi(input)
		arr = append(arr, val)
	}

	insertionSort(arr)
}

func insertionSort(arr []int) {
	for i := 1; i < len(arr); i++ {
		key := arr[i]
		j := i - 1
		for j >= 0 && arr[j] > key {
			arr[j+1] = arr[j]
			j--
		}
		arr[j+1] = key
		fmt.Println(arr)
	}
}

