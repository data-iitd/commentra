package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Println("Enter the number of elements in the array")
	input, _ := reader.ReadString('\n')
	input = strings.TrimSpace(input)
	n, _ := strconv.Atoi(input)
	array := make([]int, n+1)
	fmt.Println("Enter the elements of the array")
	for i := 1; i <= n; i++ {
		fmt.Printf("Enter the element at index %d: ", i)
		input, _ := reader.ReadString('\n')
		input = strings.TrimSpace(input)
		array[i], _ = strconv.Atoi(input)
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

