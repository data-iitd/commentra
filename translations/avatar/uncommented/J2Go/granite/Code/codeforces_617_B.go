
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(reader.ReadLine()[2 : len(reader.ReadLine())-1])
	arr := make([]int, 0)
	for i := 0; i < n; i++ {
		tmp, _ := strconv.Atoi(reader.ReadLine()[2 : len(reader.ReadLine())-1])
		if tmp == 1 {
			arr = append(arr, i)
		}
	}
	if len(arr) == 0 {
		fmt.Println(0)
	} else {
		result := int64(1)
		for i := 1; i < len(arr); i++ {
			result *= int64(arr[i] - arr[i-1])
		}
		fmt.Println(result)
	}
}

