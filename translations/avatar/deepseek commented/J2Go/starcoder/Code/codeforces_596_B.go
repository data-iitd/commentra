
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
	fmt.Println("Enter the size of the array")
	input, _ := reader.ReadString('\n')
	input = strings.TrimSpace(input)
	n, _ := strconv.Atoi(input)
	arr := make([]int, n)
	fmt.Println("Enter the elements of the array")
	for i := 0; i < n; i++ {
		fmt.Println("Enter the element", i+1)
		input, _ := reader.ReadString('\n')
		input = strings.TrimSpace(input)
		arr[i], _ = strconv.Atoi(input)
	}
	answer := 0
	for i := 0; i < n; i++ {
		if i == 0 {
			answer = arr[i]
		} else {
			answer += int(math.Abs(float64(arr[i] - arr[i-1])))
		}
	}
	fmt.Println(answer)
}

