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
	fmt.Println("Enter the value of d")
	d, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	fmt.Println("Enter the elements of the array")
	nums := make([]int, n)
	for i := 0; i < n; i++ {
		nums[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	}
	result := 0
	a := 0
	for i := 1; i < n; i++ {
		a = (nums[i-1] - nums[i])
		if a >= 0 {
			result += a/d + 1
			nums[i] += (a/d + 1) * d
		}
	}
	fmt.Println(result)
}

