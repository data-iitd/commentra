package main

import (
	"fmt"
)

func main() {
	var inp int
	fmt.Scan(&inp)

	lista := make([]int, inp)
	for i := 0; i < inp; i++ {
		fmt.Scan(&lista[i])
	}

	for i := 0; i < len(lista); i++ {
		if i == 0 {
			fmt.Printf("%d %d\n", lista[i+1]-lista[i], lista[len(lista)-1]-lista[i])
			continue
		}
		if i == len(lista)-1 {
			fmt.Printf("%d %d\n", lista[len(lista)-1]-lista[len(lista)-2], lista[len(lista)-1]-lista[0])
			continue
		}
		if lista[i]-lista[i-1] > lista[i+1]-lista[i] {
			fmt.Printf("%d ", lista[i+1]-lista[i])
		} else {
			fmt.Printf("%d %d ", lista[i]-lista[i-1], lista[i]-lista[0])
			if lista[len(lista)-1]-lista[i] > lista[i]-lista[0] {
				fmt.Printf("%d\n", lista[len(lista)-1]-lista[i])
			} else {
				fmt.Printf("%d\n", lista[i]-lista[0])
			}
		}
	}
}

