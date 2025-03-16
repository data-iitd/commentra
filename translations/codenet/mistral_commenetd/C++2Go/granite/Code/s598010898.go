

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
	a := make([]int, n)
	b := make([]int, n)
	sum := 0
	for i := 0; i < n; i++ {
		a[i], _ = strconv.Atoi(reader.ReadLine()[2 : len(reader.ReadLine())-1])
	}
	for i := 0; i < n; i++ {
		b[i], _ = strconv.Atoi(reader.ReadLine()[2 : len(reader.ReadLine())-1])
		if a[i]-b[i] > 0 {
			sum += a[i] - b[i]
		}
	}
	fmt.Println(sum)
}

