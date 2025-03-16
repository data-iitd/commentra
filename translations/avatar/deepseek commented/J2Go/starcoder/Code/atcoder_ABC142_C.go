package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Step 1: Read the input value N, which represents the number of elements.
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter the number of elements: ")
	input, _ := reader.ReadString('\n')
	N, _ := strconv.Atoi(strings.TrimSpace(input))

	// Step 2: Create a map idorder to store the elements and their corresponding positions.
	idorder := make(map[int]int)

	// Step 3: Read each element and store its value and position in the map.
	for i := 1; i <= N; i++ {
		fmt.Print("Enter element ", i, ": ")
		input, _ := reader.ReadString('\n')
		A, _ := strconv.Atoi(strings.TrimSpace(input))
		idorder[A] = i
	}

	// Step 4: Print the positions of the elements in the order they were read.
	for i := 1; i <= N; i++ {
		fmt.Print(idorder[i], " ")
	}
}

