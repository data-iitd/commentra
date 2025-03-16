
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
	n, _ := strconv.Atoi(reader.ReadLine()[2 : len(reader.ReadLine())])
	arr := make([]int, n)
	sum := 0
	for i := 0; i < n; i++ {
		arr[i], _ = strconv.Atoi(reader.ReadLine()[2 : len(reader.ReadLine())])
		sum += arr[i]
	}
	c := 0
	sb := strings.Builder{}
	for i := 0; i < n; i++ {
		if (sum-arr[i])%(n-1) == 0 && (sum-arr[i])/(n-1) == arr[i] {
			c++
			sb.WriteString(strconv.Itoa(i + 1) + " ")
		}
	}
	fmt.Println(c)
	fmt.Println(sb.String())
}

