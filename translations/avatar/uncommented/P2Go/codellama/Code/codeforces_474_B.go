package main

import "fmt"

func main() {
	var L []int
	fmt.Scanln()
	r := 1
	for _, k := range fmt.Sscanln() {
		L = append(L, r)
		r++
	}
	fmt.Scanln()
	for _, j := range fmt.Sscanln() {
		fmt.Println(L[j-1])
	}
}

