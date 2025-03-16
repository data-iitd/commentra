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

	// Take the number of elements in the array as input
	n, _ := strconv.Atoi(readLine(reader))

	// Initialize an empty list 'arr' of size 'n' and fill it with integers taken as input
	arrStr, _ := reader.ReadString('\n')
	arrStr = strings.TrimSpace(arrStr)
	arr := []int{}
	for _, numStr := range strings.Split(arrStr, " ") {
		num, _ := strconv.Atoi(numStr)
		arr = append(arr, num)
	}

	// Initialize an empty list 'ans' of size 'n' with zeros
	ans := make([]int, n)

	// Variable 'mx' stores the maximum element in the array
	mx := arr[n-1]

	// Iterate through the array from index 'n-2' to '0' in reverse order
	for i := n - 2; i >= 0; i-- {

		// Update the answer at current index 'i' based on the maximum element 'mx' and current element 'arr[i]'
		ans[i] = max(0, mx-arr[i]+1)

		// If the current element 'arr[i]' is greater than the maximum element 'mx', update 'mx'
		if arr[i] > mx {
			mx = arr[i]
		}
	}

	// Print the answer list
	for _, val := range ans {
		fmt.Print(val, " ")
	}
	fmt.Println()
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err != nil {
		panic(err)
	}
	return strings.TrimSpace(string(str))
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
