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
	reader := bufio.NewReader(os.Stdin)
<<<<<<< HEAD
	fmt.Println("Enter the size of the array")
	n, _ := strconv.Atoi(strings.TrimSpace(reader.ReadString()))
	data := make([]int, n)
	fmt.Println("Enter the array elements")
	for i := 0; i < n; i++ {
		data[i], _ = strconv.Atoi(strings.TrimSpace(reader.ReadString()))
=======
	fmt.Print("Enter the size of the array: ")
	input, _ := reader.ReadString('\n')
	input = strings.TrimSuffix(input, "\n")
	n, _ := strconv.Atoi(input)
	data := make([]int, n)
	fmt.Print("Enter the elements of the array: ")
	for i := 0; i < n; i++ {
		fmt.Print("data[", i, "]: ")
		input, _ := reader.ReadString('\n')
		input = strings.TrimSuffix(input, "\n")
		data[i], _ = strconv.Atoi(input)
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

