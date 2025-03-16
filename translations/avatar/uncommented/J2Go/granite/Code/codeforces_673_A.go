
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(reader.ReadLine()[2:])
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i], _ = strconv.Atoi(reader.ReadLine())
	}
	result, pos, flag := 0, 0, 0
	if a[0] > 15 {
		result = 15
	} else {
		for i := 1; i < n; i++ {
			if a[i]-a[i-1] > 15 {
				pos, flag = i-1, 1
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

