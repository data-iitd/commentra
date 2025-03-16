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
	fmt.Println("Enter the number of elements in the range")
	m, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	arr := make([]int, n)
	gen := make([]int, m+1)
	fmt.Println("Enter the elements of the array")
	for i := 0; i < n; i++ {
		arr[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString()))
		gen[arr[i]]++
	}
	ans := 0
	for i := 1; i <= m; i++ {
		for k := 1; k <= m; k++ {
			if i!= k {
				ans += gen[i] * gen[k]
			}
		}
	}
	fmt.Println(ans / 2)
}

