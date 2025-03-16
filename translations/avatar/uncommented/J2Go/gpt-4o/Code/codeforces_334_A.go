package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)
	square := n * n
	odd := []int{}
	even := []int{}

	for i := 1; i <= square; i++ {
		if i%2 == 0 {
			even = append(even, i)
		} else {
			odd = append(odd, i)
		}
	}

	loop := square / n
	div := loop / 2
	debug(div)

	for i := 1; i <= loop; i++ {
		for j := 0; j < div; j++ {
			if i%2 == 1 {
				fmt.Printf("%d %d ", odd[0], even[len(even)-1])
				odd = odd[1:] // remove first element
				even = even[:len(even)-1] // remove last element
			} else {
				fmt.Printf("%d %d ", even[0], odd[len(odd)-1])
				even = even[1:] // remove first element
				odd = odd[:len(odd)-1] // remove last element
			}
		}
		fmt.Println()
	}
}

func debug(obj ...interface{}) {
	fmt.Println(obj)
}
