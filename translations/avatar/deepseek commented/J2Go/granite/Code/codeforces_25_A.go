
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter the number of elements in the array: ")
	n, _ := strconv.Atoi(reader.ReadLine()[0])
	array := make([]int, n+1)
	fmt.Println("Enter the elements of the array:")
	for i := 1; i <= n; i++ {
		num, _ := strconv.Atoi(reader.ReadLine()[0])
		array[i] = num
	}
	odd := 0
	even := 0
	odd_ind := 0
	even_ind := 0
	for i := 1; i <= n; i++ {
		if array[i]%2 == 0 {
			even++
			even_ind = i
		} else {
			odd++
			odd_ind = i
		}
	}
	if odd > even {
		fmt.Println(even_ind)
	} else {
		fmt.Println(odd_ind)
	}
}

