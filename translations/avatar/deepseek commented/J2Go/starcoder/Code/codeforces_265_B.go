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
	fmt.Println("Enter the size of the array")
	size, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	arr := make([]int, size)
	fmt.Println("Enter the elements of the array")
	for i := 0; i < size; i++ {
		arr[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	}
	ans := arr[0] + 1
	for i := 1; i < size; i++ {
		ans += abs(arr[i] - arr[i-1]) + 2
	}
	fmt.Println(ans)
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

