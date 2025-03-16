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
	fmt.Println("Enter the number of elements in the list:")
	n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	fmt.Println("Enter the kth smallest number:")
	k, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	fmt.Println("Enter the list of numbers:")
	nums := make([]int, n)
	for i := 0; i < n; i++ {
		nums[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	}
	sort.Ints(nums)
	fmt.Println(nums[:k])
}

