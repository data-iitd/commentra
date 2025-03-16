<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	var n int
	fmt.Print("Enter the number of elements: ")
<<<<<<< HEAD
	fmt.Scanln(&n)
	data := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Print("Enter element ", i+1, ": ")
		fmt.Scanln(&data[i])
=======
	fmt.Scanf("%d\n", &n)
	data := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Print("Enter element ", i+1, ": ")
		fmt.Scanf("%d", &data[i])
>>>>>>> 98c87cb78a (data updated)
	}
	max := 0
	index := 0
	for i := 0; i < n; i++ {
		if data[i] > max {
			max = data[i]
			index = i
		}
	}
	a := 0
	for i := 0; i < n; i++ {
		if i!= index {
			a += data[i]
		}
	}
	if a > max {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}

