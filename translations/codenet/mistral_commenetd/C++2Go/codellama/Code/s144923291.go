
package main

import (
	"fmt"
	"math"
	"strconv"
)

func main() {
	var h, w int
	fmt.Scan(&h, &w)
	t := make([]string, h)
	s := "snuke"
	for i := 0; i < h; i++ {
		for j := 0; j < w; j++ {
			fmt.Scan(&t[i])
			if t[i] == s {
				fmt.Println(string(int('A')+j), i+1)
				return
			}
		}
	}
}

