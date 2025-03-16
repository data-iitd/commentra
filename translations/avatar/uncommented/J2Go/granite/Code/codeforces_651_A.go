
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	a, _ := strconv.Atoi(reader.ReadLine()[2 : len(reader.ReadLine())])
	b, _ := strconv.Atoi(reader.ReadLine()[2 : len(reader.ReadLine())])
	c := 0
	if a == 1 && b == 1 {
		fmt.Println(0)
	} else {
		for a >= 1 || b >= 1 {
			if a >= b {
				b++
				a -= 2
			} else {
				a++
				b -= 2
			}
			if a <= 0 || b <= 0 {
				c++
				break
			}
			c++
		}
		fmt.Println(c)
	}
}

// 