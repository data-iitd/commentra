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
	arr := make([]int, n)
	fmt.Println("Enter the elements of the array")
	for i := 0; i < n; i++ {
		arr[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	}
	if len(arr) == 0 {
		fmt.Println(0)
	} else {
		result := 1
		for i := 1; i < len(arr); i++ {
			result *= arr[i] - arr[i-1]
		}
		fmt.Println(result)
	}
}

