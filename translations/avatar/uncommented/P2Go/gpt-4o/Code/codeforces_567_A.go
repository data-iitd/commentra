package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var inp int
	fmt.Scan(&inp)

	var lista []int
	var input string
	fmt.Scan(&input)
	for _, x := range strings.Split(input, " ") {
		num, _ := strconv.Atoi(x)
		lista = append(lista, num)
	}

	for i := 0; i < len(lista); i++ {
		if i == 0 {
			fmt.Printf("%d %d\n", lista[i+1]-lista[i], lista[len(lista)-1]-lista[i])
			continue
		} else if i == len(lista)-1 {
			fmt.Printf("%d %d\n", lista[len(lista)-1]-lista[len(lista)-2], lista[len(lista)-1]-lista[0])
			continue
		} else if lista[i]-lista[i-1] > lista[i+1]-lista[i] {
			fmt.Print(lista[i+1]-lista[i], " ")
		} else {
			fmt.Print(lista[i]-lista[i-1], " ")
		}
		if lista[len(lista)-1]-lista[i] > lista[i]-lista[0] {
			fmt.Println(lista[len(lista)-1]-lista[i])
		} else {
			fmt.Println(lista[i] - lista[0])
		}
	}
}

// <END-OF-CODE>
