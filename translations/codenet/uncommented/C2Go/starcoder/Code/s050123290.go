package main

import "fmt"

func main() {
	var su [1000]byte
	var susum int
	var j int

	for {
		for j = 0; j <= 1000; j++ {
			fmt.Scanf("%c", &su[j])
			if su[j] == '\n' {
				break
			}
			susum = susum + int(su[j]-'0')
		}
		if su[0] == '0' {
			break
		}
		fmt.Printf("%d\n", susum)
		susum = 0
	}
}

