package main

import (
	"fmt"
)

func main() {
	var num int
	fmt.Scan(&num)
	counter := 0
	fine := 0
	arr := make([]string, num)

	for i := 0; i < num; i++ {
		fmt.Scan(&arr[i])
	}

	for i := 0; i < num; i++ {
		for k := 0; k < num; k++ {
			if arr[k][i] == 'C' {
				counter++
			}
		}
		fine += (counter * (counter - 1)) / 2
		counter = 0
	}

	for i := 0; i < num; i++ {
		for k := 0; k < num; k++ {
			if arr[i][k] == 'C' {
				counter++
			}
		}
		fine += (counter * (counter - 1)) / 2
		counter = 0
	}

	fmt.Println(fine)
}

// <END-OF-CODE>
