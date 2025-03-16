package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	var n int
	fmt.Scan(&n)
	var square int = n * n
	var odd []int
	var even []int
	for i := 1; i <= square; i++ {
		if i%2 == 0 {
			even = append(even, i)
		} else {
			odd = append(odd, i)
		}
	}
	var loop int = square / n
	var div int = loop / 2
	debug(div)
	for i := 1; i <= loop; i++ {
		for j := 0; j < div; j++ {
			if i%2 == 1 {
				fmt.Print(odd[0], " ", even[len(even)-1], " ")
				odd = odd[1:]
				even = even[:len(even)-1]
			} else {
				fmt.Print(even[0], " ", odd[len(odd)-1], " ")
				even = even[1:]
				odd = odd[:len(odd)-1]
			}
		}
		fmt.Println()
	}
}

func debug(obj ...interface{}) {
	fmt.Fprintln(os.Stderr, obj...)
}

