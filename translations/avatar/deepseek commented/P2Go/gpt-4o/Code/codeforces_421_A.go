package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var n, a, b int
	fmt.Scan(&n, &a, &b)
	
	// Read the first list
	var lista []int
	input := ""
	fmt.Scan(&input)
	for _, str := range strings.Split(input, " ") {
		num, _ := strconv.Atoi(str)
		lista = append(lista, num)
	}
	
	// Read the second list
	var listb []int
	input = ""
	fmt.Scan(&input)
	for _, str := range strings.Split(input, " ") {
		num, _ := strconv.Atoi(str)
		listb = append(listb, num)
	}
	
	// Create a map for quick lookup
	listaMap := make(map[int]bool)
	for _, value := range lista {
		listaMap[value] = true
	}
	
	// Iterate and print results
	for k := 1; k <= n; k++ {
		if _, exists := listaMap[k]; exists {
			fmt.Print(1, " ")
		} else {
			fmt.Print(2, " ")
		}
	}
}

// <END-OF-CODE>
