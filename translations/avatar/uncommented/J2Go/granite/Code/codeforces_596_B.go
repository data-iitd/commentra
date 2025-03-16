
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
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		arr[i], _ = strconv.Atoi(reader.ReadLine()[2 : len(reader.ReadLine())-1])
	}
	answer := int(math.Abs(float64(arr[0])))
	for i := 1; i < n; i++ {
		answer += int(math.Abs(float64(arr[i]-arr[i-1])))
	}
	fmt.Println(answer)
}

