
package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var num int
	var counter int
	var fine int
	var arr []string

	// Read the size of the grid
	num, _ = strconv.Atoi(os.Args[1])

	// Read num strings representing the grid rows
	for i := 0; i < num; i++ {
		arr = append(arr, os.Args[i+2])
	}

	// Calculate the fine for each column
	for i := 0; i < num; i++ {
		for k := 0; k < num; k++ {
			if arr[k][i] == 'C' {
				counter++
			}
		}
		fine += (counter * (counter - 1)) / 2
		counter = 0
	}

	// Calculate the fine for each row
	for i := 0; i < num; i++ {
		for k := 0; k < num; k++ {
			if arr[i][k] == 'C' {
				counter++
			}
		}
		fine += (counter * (counter - 1)) / 2
		counter = 0
	}

	// Print the total fine
	fmt.Println(fine)
}

