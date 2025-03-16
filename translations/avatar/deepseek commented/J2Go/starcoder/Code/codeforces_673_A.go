
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
	fmt.Println("Enter the number of elements in the list `a`")
	n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	a := make([]int, n)
	fmt.Println("Enter the elements of the list `a`")
	for i := 0; i < n; i++ {
		a[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	}
	result, pos, flag := 0, 0, 0
	if a[0] > 15 {
		result = 15
	} else {
		for i := 1; i < n; i++ {
			if a[i]-a[i-1] > 15 {
				pos = i - 1
				flag = 1
				break
			}
		}
		if flag == 1 {
			result = a[pos] + 15
		} else {
			result = a[n-1] + 15
		}
	}
	if result > 90 {
		result = 90
	}
	fmt.Println(result)
}

