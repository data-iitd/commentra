
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(reader.ReadLine()[2 : len(reader.ReadLine())-1])
	array := make([]int, n+1)
	for i := 1; i <= n; i++ {
		array[i], _ = strconv.Atoi(reader.ReadLine()[2 : len(reader.ReadLine())-1])
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
