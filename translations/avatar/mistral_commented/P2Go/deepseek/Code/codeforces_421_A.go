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
	
	// Reading n, a, and b
	input1, _ := reader.ReadString('\n')
	input1 = strings.TrimSpace(input1)
	inputs := strings.Split(input1, " ")
	n, _ := strconv.Atoi(inputs[0])
	a, _ := strconv.Atoi(inputs[1])
	b, _ := strconv.Atoi(inputs[2])
	
	// Reading lista
	input2, _ := reader.ReadString('\n')
	input2 = strings.TrimSpace(input2)
	listaStr := strings.Split(input2, " ")
	lista := make([]int, len(listaStr))
	for i, str := range listaStr {
		lista[i], _ = strconv.Atoi(str)
	}
	
	// Reading listb
	input3, _ := reader.ReadString('\n')
	input3 = strings.TrimSpace(input3)
	listbStr := strings.Split(input3, " ")
	listb := make([]int, len(listbStr))
	for i, str := range listbStr {
		listb[i], _ = strconv.Atoi(str)
	}
	
	// Iterating through the range of n
	for k := 0; k < n; k++ {
		// Checking if k+1 is present in the lista list
		found := false
		for _, val := range lista {
			if k+1 == val {
				found = true
				break
			}
		}
		// Printing 1 if k+1 is present in the lista list
		if found {
			fmt.Print("1 ")
		} else {
			// Printing 2 if k+1 is not present in the lista list
			fmt.Print("2 ")
		}
	}
	fmt.Println()
}
