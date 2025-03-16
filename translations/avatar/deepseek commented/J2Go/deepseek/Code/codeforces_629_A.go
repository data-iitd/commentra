package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	counter := 0
	fine := 0
	var arr []string

	// Read num strings representing the grid rows
	for i := 0; i < num; i++ {
		scanner.Scan()
		s := scanner.Text()
		arr = append(arr, s)
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

