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
	fmt.Println("Enter the number of elements in the requirement list")
	n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	fmt.Println("Enter the number of elements in the pre-requisite list")
	m, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	req := make([]int, n)
	pre := make([]int, m)
	fmt.Println("Enter the elements of the requirement list")
	for i := 0; i < n; i++ {
		req[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	}
	fmt.Println("Enter the elements of the pre-requisite list")
	for i := 0; i < m; i++ {
		pre[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	}
	i := n - 1
	j := m - 1
	ans := 0
	for i >= 0 && j >= 0 {
		if req[i] > pre[j] {
			ans++
		} else {
			j--
		}
		i--
	}
	fmt.Println(ans + i + 1)
}

