
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
	a, b, c := 0, 0, 0
	for i := 0; i < n; i++ {
		x, _ := strconv.Atoi(reader.ReadLine()[2 : len(reader.ReadLine())-1])
		a += x
	}
	for i := 0; i < n-1; i++ {
		x, _ := strconv.Atoi(reader.ReadLine()[2 : len(reader.ReadLine())-1])
		b += x
	}
	for i := 0; i < n-2; i++ {
		x, _ := strconv.Atoi(reader.ReadLine()[2 : len(reader.ReadLine())-1])
		c += x
	}
	fmt.Println(a - b)
	fmt.Println(b - c)
}

