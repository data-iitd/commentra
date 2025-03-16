package main

import (
	"fmt"
)

func main() {
	var su [1000]rune
	var susum int
	var j int
	
	for {
		susum = 0
		for j = 0; j < 1000; j++ {
			var input rune
			fmt.Scanf("%c", &input)
			su[j] = input
			if su[j] == '\n' {
				break
			}
			susum += int(su[j] - '0')
		}
		if su[0] == '\n' {
			break
		}
		fmt.Println(susum)
	}
}

