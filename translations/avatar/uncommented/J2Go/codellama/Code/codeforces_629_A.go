package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	sc := make([]string, 0)
	var num int
	var counter int
	var fine int
	var s string
	var k int
	var arr []string

	num, _ = strconv.Atoi(os.Args[1])
	for i := 0; i < num; i++ {
		s = os.Args[i+2]
		sc = append(sc, s)
	}
	for i := 0; i < num; i++ {
		for k := 0; k < num; k++ {
			if sc[k][i] == 'C' {
				counter++
			}
		}
		fine += (counter * (counter - 1)) / 2
		counter = 0
	}
	for i := 0; i < num; i++ {
		for k := 0; k < num; k++ {
			if sc[i][k] == 'C' {
				counter++
			}
		}
		fine += (counter * (counter - 1)) / 2
		counter = 0
	}
	fmt.Println(fine)
}

