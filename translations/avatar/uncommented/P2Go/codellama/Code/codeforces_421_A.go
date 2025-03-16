
package main

import "fmt"

func main() {
	var n, a, b int
	fmt.Scan(&n, &a, &b)
	var lista []int
	for i := 0; i < n; i++ {
		var x int
		fmt.Scan(&x)
		lista = append(lista, x)
	}
	var listb []int
	for i := 0; i < n; i++ {
		var x int
		fmt.Scan(&x)
		listb = append(listb, x)
	}
	for k := 0; k < n; k++ {
		if lista[k] == k+1 {
			fmt.Print(1, " ")
		} else {
			fmt.Print(2, " ")
		}
	}
}

