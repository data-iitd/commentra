
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
	ans := arr[0] + 1
	for i := 1; i < n; i++ {
		ans += int(math.Abs(float64(arr[i]-arr[i-1]))) + 2
	}
	fmt.Println(ans)
}

