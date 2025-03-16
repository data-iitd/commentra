
package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	var n int
	fmt.Scan(&n)
	square := n * n
	odd := make([]int, 0)
	even := make([]int, 0)
	for i := 1; i <= square; i++ {
		if i%2 == 0 {
			even = append(even, i)
		} else {
			odd = append(odd, i)
		}
	}
	loop := square / n
	div := loop / 2
	// debug(div)
	for i := 1; i <= loop; i++ {
		for j := 0; j < div; j++ {
			if i%2 == 1 {
				fmt.Print(strconv.Itoa(odd[0]) + " " + strconv.Itoa(even[len(even)-1]) + " ")
				odd = odd[1:]
				even = even[:len(even)-1]
			} else {
				fmt.Print(strconv.Itoa(even[0]) + " " + strconv.Itoa(odd[len(odd)-1]) + " ")
				even = even[1:]
				odd = odd[:len(odd)-1]
			}
		}
		fmt.Println()
	}
}

// 