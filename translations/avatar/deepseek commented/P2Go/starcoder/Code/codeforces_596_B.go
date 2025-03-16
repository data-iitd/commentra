
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
	fmt.Println("Enter the number of elements in the list `r`:")
	n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	fmt.Println("Enter the space-separated string of integers and convert them to a list of integers:")
	r := make([]int, n)
	for i := 0; i < n; i++ {
		r[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	}
	ans := 0
	for i := 0; i < n; i++ {
		ans += abs(r[i] - r[i-1])
	}
	fmt.Println(ans)
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

