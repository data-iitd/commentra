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
	n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	array := make([]int, n+1)
	fmt.Println("Enter the elements of the array")
	for i := 1; i <= n; i++ {
		array[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString('\n')))
	}
	odd, even, odd_ind, even_ind := 0, 0, 0, 0
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

