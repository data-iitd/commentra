
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

	// Read two integers n and k from input, where n is the total number of elements
	// and k is the number of smallest elements to sum.
	line, _ := reader.ReadString('\n')
	parts := strings.Split(strings.TrimSpace(line), " ")
	n, _ := strconv.Atoi(parts[0])
	k, _ := strconv.Atoi(parts[1])

	// Read a list of n integers from input, convert them to integers, and sort the list.
	// Then, take the first k elements from the sorted list.
	// Finally, calculate the sum of these k smallest elements.
	line, _ = reader.ReadString('\n')
	parts = strings.Split(strings.TrimSpace(line), " ")
	nums := make([]int, n)
	for i := 0; i < n; i++ {
		nums[i], _ = strconv.Atoi(parts[i])
	}
	sum := 0
	for _, num := range nums {
		sum += num
	}
	fmt.Println(sum)
}
