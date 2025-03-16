

package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	fmt.Print("Enter the number of elements: ")
	n, _ := strconv.Atoi(reader.ReadLine())

	x := make([]int, n)
	y := make([]int, n)

	for i := 0; i < n; i++ {
		fmt.Print("Enter element ", i+1, ": ")
		x[i], _ = strconv.Atoi(reader.ReadLine())
		y[i] = x[i]
	}

	sort.Ints(y)

	y_mid := y[n/2]

	for i := 0; i < n; i++ {
		if x[i] < y_mid {
			fmt.Println(y_mid)
		} else {
			fmt.Println(y[n/2-1])
			break
		}
	}
}

