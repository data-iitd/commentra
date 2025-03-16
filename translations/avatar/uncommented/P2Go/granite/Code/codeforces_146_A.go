
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(reader.ReadLine()[2 : len(reader.ReadLine())])
	number := make([]int, n)
	for i := 0; i < n; i++ {
		number[i], _ = strconv.Atoi(string(reader.ReadByte()))
	}
	h1 := 0
	h2 := 0
	x := 0
	for i := 0; i < n; i++ {
		if number[i]!= 4 && number[i]!= 7 {
			fmt.Println("NO")
			x += 1
			break
		}
		if i < n/2 {
			h1 += number[i]
		} else {
			h2 += number[i]
		}
	}
	if x == 0 {
		if h1 == h2 {
			fmt.Println("YES")
		} else {
			fmt.Println("NO")
		}
	}
}
