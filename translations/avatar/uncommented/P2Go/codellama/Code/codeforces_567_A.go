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
	lista = strings.Split(fmt.Sprint(lista), " ")
	for i := 0; i < len(lista); i++ {
		if i == 0 {
			fmt.Printf("%d %d\n", strconv.Atoi(lista[i+1])-strconv.Atoi(lista[i]), strconv.Atoi(lista[len(lista)-1])-strconv.Atoi(lista[i]))
			continue
		} else if i == len(lista)-1 {
			fmt.Printf("%d %d\n", strconv.Atoi(lista[len(lista)-1])-strconv.Atoi(lista[len(lista)-2]), strconv.Atoi(lista[len(lista)-1])-strconv.Atoi(lista[0]))
			continue
		} else if strconv.Atoi(lista[i])-strconv.Atoi(lista[i-1]) > strconv.Atoi(lista[i+1])-strconv.Atoi(lista[i]) {
			fmt.Printf("%d ", strconv.Atoi(lista[i+1])-strconv.Atoi(lista[i]))
		} else {
			fmt.Printf("%d ", strconv.Atoi(lista[i])-strconv.Atoi(lista[i-1]))
		}
		if strconv.Atoi(lista[len(lista)-1])-strconv.Atoi(lista[i]) > strconv.Atoi(lista[i])-strconv.Atoi(lista[0]) {
			fmt.Printf("%d\n", strconv.Atoi(lista[len(lista)-1])-strconv.Atoi(lista[i]))
		} else {
			fmt.Printf("%d\n", strconv.Atoi(lista[i])-strconv.Atoi(lista[0]))
		}
	}
}

