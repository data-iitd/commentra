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
	n, _ := strconv.Atoi(reader.ReadString('\n'))
	arr := make([]int, n)
	sum := 0
	fmt.Println("Enter the elements of the array")
	for i := 0; i < n; i++ {
		arr[i], _ = strconv.Atoi(reader.ReadString('\n'))
		sum += arr[i]
	}
	c := 0
	sb := strings.Builder{}
	for i := 0; i < n; i++ {
		if (sum-arr[i])%(n-1) == 0 && (sum-arr[i])/(n-1) == arr[i] {
			c++
			sb.WriteString(fmt.Sprintf("%d ", i+1))
		}
	}
	fmt.Println(c)
	fmt.Println(sb.String())
}

