
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
	fmt.Println("Enter the number of integers")
	n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	fmt.Println("Enter the number of pairs")
	m, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	arr := make([]int, n)
	gen := make([]int, 11)
	for i := 0; i < n; i++ {
		fmt.Println("Enter the integer")
		arr[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
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

