package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	var a, c, k, b int

	for {
		_, err := fmt.Scan(&a)
		if err != nil {
			if err == os.EOF {
				break
			}
			fmt.Println(err)
			os.Exit(1)
		}

		c = 0
		k = 0

		if a < 3 {
			fmt.Println(0)
			break
		}

		b = a

		for a > 0 {
			b--
			c++
			if c == 3 {
				k++
				c = 0
			}
			a--
		}

		fmt.Println(k)
	}
}

