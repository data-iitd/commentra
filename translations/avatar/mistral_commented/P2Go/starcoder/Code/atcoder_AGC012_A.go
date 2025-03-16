
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
	fmt.Println("Enter the number of integers")
	n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	fmt.Println("Enter the integers")
	A := make([]int, n)
	for i := 0; i < n; i++ {
		A[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	}
	sort.Ints(A)
	ans := 0
	for i := len(A) - 2; i >= len(A)-2*n-1; i -= 2 {
		ans += A[i]
	}
	fmt.Println(ans)
}

