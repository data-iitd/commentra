package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	num := 0
	fmt.Sscanf(scanner.Text(), "%d", &num)
	arr := []string{}
	for i := 0; i < num; i++ {
		scanner.Scan()
		s := scanner.Text()
		arr = append(arr, s)
	}
	counter := 0
	fine := 0
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

