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

	// Read three integers from input: n (number of elements), a, and b
	input, _ := reader.ReadString('\n')
	parts := strings.Split(strings.TrimSpace(input), " ")
	n, _ := strconv.Atoi(parts[0])
	a, _ := strconv.Atoi(parts[1])
	b, _ := strconv.Atoi(parts[2])

	// Read a list of integers from input and store it in lista
	input, _ = reader.ReadString('\n')
	listaStr := strings.Split(strings.TrimSpace(input), " ")
	lista := []int{}
	for _, str := range listaStr {
		num, _ := strconv.Atoi(str)
		lista = append(lista, num)
	}

	// Read another list of integers from input and store it in listb
	input, _ = reader.ReadString('\n')
	listbStr := strings.Split(strings.TrimSpace(input), " ")
	listb := []int{}
	for _, str := range listbStr {
		num, _ := strconv.Atoi(str)
		listb = append(listb, num)
	}

	// Iterate through the range of n (from 0 to n-1)
	for k := 0; k < n; k++ {
		// Check if the current index + 1 is present in lista
		found := false
		for _, num := range lista {
			if num == k+1 {
				found = true
				break
			}
		}
		if found {
			// If present, print 1 followed by a space
			fmt.Print("1 ", "")
		} else {
			// If not present, print 2 followed by a space
			fmt.Print("2 ", "")
		}
	}
	fmt.Println() // Print newline at the end
}
