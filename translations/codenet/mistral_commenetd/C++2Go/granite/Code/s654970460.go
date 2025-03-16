
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	fmt.Print("Enter the size of the array: ")
	size, _ := reader.ReadString('\n')
	size, _ = strconv.Atoi(size)

	array := make([]int, size)

	fmt.Print("Enter the elements of the array: ")
	for i := 0; i < size; i++ {
		element, _ := reader.ReadString('\n')
		element, _ = strconv.Atoi(element)
		array[i] = element
	}

	fmt.Print(array[size-1])
	for i := size - 2; i >= 0; i-- {
		fmt.Printf(" %d", array[i])
	}

	fmt.Println()
}

