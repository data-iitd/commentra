
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	var n, d int
	fmt.Fscanf(reader, "%d\n", &n)
	fmt.Fscanf(reader, "%d\n", &d)

	nums := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscanf(reader, "%d\n", &nums[i])
	}

	result := 0
	a := 0
	for i := 1; i < n; i++ {
		a = nums[i-1] - nums[i]
		if a >= 0 {
			result += a/d + 1
			nums[i] += (a / d + 1) * d
		}
	}

	fmt.Println(result)
}

