package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var n int
	fmt.Scanf("%d", &n)
	square := n * n
	var odd, even []int
	for i := 1; i <= square; i++ {
		if i%2 == 0 {
			even = append(even, i)
		} else {
			odd = append(odd, i)
		}
	}
	loop := square / n
	div := loop / 2
	for i := 1; i <= loop; i++ {
		for j := 0; j < div; j++ {
			if i%2 == 1 {
				fmt.Printf("%d %d ", odd[0], even[len(even)-1])
				odd = odd[1:]
				even = even[:len(even)-1]
			} else {
				fmt.Printf("%d %d ", even[0], odd[len(odd)-1])
				even = even[1:]
				odd = odd[:len(odd)-1]
			}
		}
		fmt.Println()
	}
}

