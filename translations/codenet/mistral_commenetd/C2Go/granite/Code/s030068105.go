
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	fmt.Print("Enter the number of elements: ")
	n, _ := strconv.Atoi(reader.ReadLine()[0])

	data := make([]int, n)

	for i := 0; i < n; i++ {
		fmt.Printf("Enter element %d: ", i+1)
		data[i], _ = strconv.Atoi(reader.ReadLine()[0])
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

