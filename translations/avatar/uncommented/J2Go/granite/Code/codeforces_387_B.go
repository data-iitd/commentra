
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
	fmt.Println("Enter the number of elements in the first array:")
	n, _ := reader.ReadString('\n')
	n, _ = strconv.Atoi(strings.TrimSpace(n))
	fmt.Println("Enter the number of elements in the second array:")
	m, _ := reader.ReadString('\n')
	m, _ = strconv.Atoi(strings.TrimSpace(m))
	req := make([]int, n)
	pre := make([]int, m)
	fmt.Println("Enter the elements of the first array:")
	for i := 0; i < n; i++ {
		req[i], _ = reader.ReadString('\n')
		req[i], _ = strconv.Atoi(strings.TrimSpace(req[i]))
	}
	fmt.Println("Enter the elements of the second array:")
	for i := 0; i < m; i++ {
		pre[i], _ = reader.ReadString('\n')
		pre[i], _ = strconv.Atoi(strings.TrimSpace(pre[i]))
	}
	i, j := n-1, m-1
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
